
#ifndef FACPP_HPP
#define FACPP_HPP 1

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

//$Id$

#include <boost/smart_ptr.hpp>
#include <iostream>
#include <boost/program_options.hpp>
#include <string>
#include <fstream>

#ifdef USE_BOOST_THREADS
#include "boost/thread/mutex.hpp"
#include <boost/thread.hpp>
//#include <boost/thread/thread.hpp>
#else
//#ifdef USE_GLIB_THREADS
#include <glibmm/threadpool.h>
#endif

unsigned int NUM_THREADS = 4;

typedef std::vector< std::string > vecStr_t;


//using boost::mutex;

//boost::mutex lock;


struct DbgOutput
{
    void operator ( ) ( const char* file, const char* pfunc, \
            const long line, const std::string& msg="" )
    {
#ifdef USE_BOOST_THREADS
        boost::mutex::scoped_lock scoped_lock(mutex);
#else
        Glib::Mutex::Lock lock (mutex);
#endif
        //std::cout << "D:" << __PRETTY_FUNCTION__ << ":"
        //        << __LINE__ << ":" << (*it)
        //        << std::endl;
        std::cerr << "D:" << file << ":" << line << ":"
                << pfunc << ":" << msg
                << std::endl;
    }
#ifdef USE_BOOST_THREADS
    boost::mutex mutex;
#else
    Glib::StaticMutex mutex;
#endif
};

//#ifdef USE_GLIB_THREADS
//Glib::StaticMutex mutex = GLIBMM_STATIC_MUTEX_INIT;
//#endif

#ifdef USE_BOOST_THREADS
//class Facpp
struct Facpp
{
//public:
   //Facpp( )
   //   : recordsRead( 0 ),
   //     recordsWritten( 0 ),
   //     lines(),
   //     rendezvous( NUM_THREADS )
   //{ }

   Facpp( vecStr_t& vecStr
//#ifdef USE_BOOST_THREADS
           , boost::barrier& barrier
//#endif
        )
      : recordsRead( 0 )
        ,recordsWritten( 0 )
        ,lines( vecStr )
//#ifdef USE_BOOST_THREADS
        ,rendezvous( barrier )
//#endif
   { }
   void operator()()
   {
//#ifdef USE_BOOST_THREADS
       rendezvous.wait( );
//#endif
      recordsRead = lines.size( );
      //std::cout << "ThrdId: " << (*this)->get_id() << std::endl;
//#ifdef USE_BOOST_THREADS
      std::cout << "ThrdId: " << boost::thread::id() << std::endl;
//#endif
   }

   const long getRecordsRead( ) const
   { return lines.size( ); }

//private:
   long recordsRead;
   long recordsWritten;
   vecStr_t lines;
//#ifdef USE_BOOST_THREADS
   boost::barrier& rendezvous;
//#endif
};

typedef boost::shared_ptr< Facpp > p_Facpp_t;
typedef std::vector< p_Facpp_t > vec_p_Facpp_t;
typedef std::vector< Facpp* > vecFacpp_t;
typedef std::vector< Facpp* >::const_iterator vecFacppIter_t;

#endif

#ifdef USE_GLIB_THREADS
Glib::StaticMutex mutex = GLIBMM_STATIC_MUTEX_INIT;

struct FacppGlib
{
//public:
   FacppGlib( )
      : recordsRead( 0 ),
        recordsWritten( 0 )
   { }

//   FacppGlib( vecStr_t& vecStr)
//      : recordsRead( 0 ),
//        recordsWritten( 0 ),
//        lines( vecStr )
//   { }

   void countLines(const vecStr_t& lines)
   {
      Glib::Mutex::Lock lock (mutex);
      recordsRead += lines.size( );
   }

   const long getRecordsRead( ) const
   { return recordsRead; }

//private:
   long recordsRead;
   long recordsWritten;
};

#endif

namespace po = boost::program_options;

bool
processArgs( int argc, char** argv, long& debug,
   std::string& filename, long& batch, unsigned int barrierSize
   )
{
   try
   {

      po::variables_map vm;
      po::options_description desc(std::string(argv[0]) + std::string(": Allowable options"));
      desc.add_options()
         ("help,h", "Display this help")
         ("filename,f", po::value< std::string >(&filename), "Name of file to be analysed")
         ("debug,d", po::value< long >(&debug), "Process the first 10 records only and generate debugging output for them.")
         ("batch-size,b", po::value< long >(&batch), "Batch size.")
         ("rendezvous-size,r", po::value< unsigned int >(&barrierSize), "Barrier size.")
         ("version,v", "Display the version")
        ;

      po::store(po::parse_command_line(argc, argv, desc), vm);
      po::notify(vm);    

      if (vm.count("help"))
      {
         std::cout << desc << std::endl;
         return false;
      }

      if (vm.count("version"))
      {
         std::cout << argv[0] << ": " 
                   << __DATE__ << " " << __TIME__ 
                   << ": " << PACKAGE_VERSION << std::endl;
         return false;
      }

      if ( vm.count("filename"))
      {
         if ( debug )
         {
            std::cout << "D:" << __func__ << ":" << __LINE__ << ": "
                      << "Filename is: " 
                      //<< vm["filename"].as< std::string >()
                      << filename
                      << std::endl;
         }
      }
      else
      {
         std::cout << "Filename was not set" << std::endl;
         return false;
      }

      if (vm.count("debug"))
      {
         if ( debug )
         {
            std::cout << "D:" << __func__ << ":" << __LINE__ << ":"
                      << "!!!DEBUG: Debugging output will be output and only 10 records will be processed"
                      << " (" << debug << ")"
                      << std::endl;
         }
      }

      if (vm.count("batch-size"))
      {
         if ( debug )
         {
             std::cout << "D:" << __func__ << ":" << __LINE__ << ":"
                      << "Batch size requested: " << batch << std::endl;
         }
      }

      if (vm.count("rendezvous-size"))
      {
         if ( debug )
         {
             std::cout << "D:" << __func__ << ":" << __LINE__ << ":"
                      << "Barrier size requested: "
                      << barrierSize 
                      << std::endl;
         }
      }
   }
   catch(std::exception& e)
   {
       std::cerr << "D:" << __func__ << ":" << __LINE__ << ":" << ": error: "
                << e.what() << std::endl;
      return false;
   }

   return true;
}


#endif

