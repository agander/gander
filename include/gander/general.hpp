#ifndef GENERAL_HPP
#define GENERAL_HPP 1

// Boost.Test
//#define BOOST_TEST_MAIN
//#include <boost/test/unit_test.hpp>

//#include <boost/test/minimal.hpp>

//#include "mehlhorn.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <iterator>
#include <vector>

#include <valarray>

#include <sstream>
#include <cctype>
#include <stdexcept>
#include <cassert>
#include <cctype>
#include <tuple>
#include <deque>
#include <set>

#include <climits>
#include <cstdlib>
#include <ctime>

//using namespace std;

using std::cout;
using std::endl;
//using std::cerr;
//using std::cin;
//using std::string;
//using std::for_each;

//typedef std::vector<std::string> vecT;
//typedef vecT::iterator vecTIter;
typedef std::vector< std::string > vec_str_t;
typedef std::vector< long > vec_long_t;
typedef std::vector< size_t > vec_sizet_t;
typedef std::deque< size_t > deq_sizet_t;
typedef std::set< size_t > set_sizet_t;

//! \typedef Found off t'web...
typedef unsigned int digit;
typedef std::vector< digit > integer;

//! \typedef Tuple of i) data and ii) data size.
typedef std::tuple< 
    std::vector< long >,            // 
    size_t                  // 
> vec_long_size_tup_t;


//! \fn time_seed
//! \copyright May be freely redistributed, but copyright notice must be retained.
//! \date 22 Jan 2004 22:59. Copyright © 2004 
//! \author  Ben Pfaff.
//! \uri <http://benpfaff.org/writings/clc/random-seed.html>
//! \par How should I pick the value to pass to srand()?
//! By default, the C random number generator produces the same sequence every 
//! time the program is run. In order to generate different sequences, it has 
//! to be “seeded” using srand() with a different value each time.
//! The function below to do this is carefully designed.
//! It uses time() to obtain the current time; the alternative clock() 
//! is a poor choice because it measures CPU time used, which may vary little 
//! from run to run. The actual value of a time_t is not portable, 
//! so it computes a “hash” of the bytes in it using a multiply-and-add technique.
//! The factor used for multiplication normally comes out as 257, a prime and therefore a good candidate.
//! References: Knuth, The Art of Computer Programming, Vol. 2: Seminumerical Algorithms, section 3.2.1;
//! Aho, Sethi, and Ullman, Compilers: Principles, Techniques, and Tools, section 7.6.
//! 
//! \brief Choose and return an initial random seed based on the current time.
//! Based on code by Lawrence Kirby <fred@genesis.demon.co.uk>.
//! \usage : srand (time_seed ());
//! \param None
//! \return unsigned

unsigned time_seed( void )
{
    std::time_t timeval;   /* Current time. */
    unsigned char *ptr;   /* Type punned pointed into timeval. */
    unsigned seed;    /* Generated seed. */
    std::size_t idx;
    
    timeval = std::time( NULL );
    ptr = (unsigned char *) &timeval;
    
    seed = 0;
    for (idx = 0; idx < sizeof timeval; ++idx )
    {
        seed = seed * (UCHAR_MAX + 2u) + ptr[idx];
    }
    
    return seed;
}


template< typename T = std::size_t >
struct strToLong
{
    T operator () ( const std::string& str )
    {
        //std::ostreamstream os;
        std::istringstream is(str);
        //os << str;
        T num;
        is >> num;
        return num;
    }
};

/*
 * long strToLong( std::string str)
 * {
 *    std::istringstream is(str);
 *    //os << str;
 *    long num;
 *    is >> num;
 *    return num;
 }
 */

//! \function 
/*
 * def sort_merge(data):
"""

"""
inversion_count = 0
inversions = 0
all_output = []
data_len = len(data)
if data_len == 2:
    if data[0] > data[1]:
        all_output += data[1:2]
        all_output += data[0:1]
        inversion_count += 1
        else:
            all_output += data[0:1]
            all_output += data[1:2]
            elif data_len > 2:
            (left, inversions) = sort_merge( data[0:data_len/2] )
            inversion_count += inversions
            all_output.extend(left)
            (right, inversions) = sort_merge( data[data_len/2:data_len] )
            inversion_count += inversions
            all_output.extend(right)
            inversion_count += merge(left, right)
            else:
                all_output = data
                
                return (all_output, inversion_count)
*/


//! \note Got the initial file read functions in 1 function.
//void load_data_file( std::string &&data_file_name)
/*vec_long_size_tup_t load_data_file( const std::string &data_file_name )
{
    
    std::ifstream data_file( data_file_name.c_str());
    
    //BOOST_CHECK( data_file.good() );
    if (!data_file.good())
    {
        //std::cerr << argv[0] << " file" << std::endl;
        std::cerr << data_file_name << " does not exist" << std::endl;
        BOOST_ERROR( std::string( data_file_name + " does not exist").c_str() );
        //return(99);
    }
    
    //std::istream_iterator<std::stri*ng> keyBegin(keyFile);
    //std::istream_iterator<std::string> keyEnd;
    //vecT keys(keyBegin, keyEnd);
    
    //! /note Import the data into the vector< string >
    std::istream_iterator< std::string > data_begin( data_file );
    std::istream_iterator< std::string > data_end;
    vec_str_t data(data_begin, data_end);
    
    //! /note Load a std::vector with the data
    long data_size = data.size();
    std::cout << __func__  << ":" << __LINE__ << ":D:size of data: "
    << data_size << " elements."
    << std::endl;
    

    vec_long_t vec_long;
    vec_long.reserve(data_size);
    std::transform( data.begin(), data.end(), std::back_inserter(vec_long), strToLong() );
    const  size_t vec_long_size = vec_long.size();
    //std::string s("hello");
    //std::string S;
    //std::transform(s.begin(), s.end(), S.begin(), (int (*)(int))std::toupper);
    //std::cout << S;
    
    std::cout << __func__ << ":" << __LINE__ << ":D:size of vec_long: "
    << vec_long_size << " elements."
    << std::endl;
    //assert( data.size() == vec_long_size );
    BOOST_REQUIRE( data.size() == vec_long_size );

    return std::make_tuple( vec_long, vec_long_size );
    
}



void load_valarray( const std::vector< long >& vec_long, size_t vec_long_size )
{
    //! \note Load and use a std::array.
    std::valarray< long > A( vec_long[0], vec_long_size );
    
    std::cout << __func__ << ":" << __LINE__ << ":D:size of A: "
              << A.size() << " elements."
              << std::endl;
    std::slice col1_s( 0, 1, 50000 );
    std::valarray< long > col1(A[col1_s]);
    //     print_seq( col1_s, "col1_s" );
    for (size_t n = 0; n < col1.size(); ++n)
    {
        std::cout << __func__ << ":" << __LINE__ 
        << ":D:col1[" << n << "]:" << col1[n]
        << std::endl;
    }
    
    std::valarray< long > left(A[0], A.size()/2);
    for (size_t n = 0; n < 5; ++n)
    {
        std::cout << __func__ << ":" << __LINE__ 
        << ":D:left[" << n << "]:" << left[n]
        << std::endl;
    }
    std::cout << __func__ << ":" << __LINE__ 
              << ":D:left[0]:" << left[0] << ", "
              << ":D:left[1]:" << left[1] << ", "
              << ":D:left[2]:" << left[2] << ", "
              << ":D:left[3]:" << left[3] << ", "
              << std::endl;
    
    std::valarray< long > right(A[(A.size()/2)-1], A.size()/2);

    std::cout << __func__ << ":" << __LINE__ 
    << ":D:right[0]:" << right[0] << ", "
    << ":D:right[1]:" << right[1] << ", "
    << ":D:right[2]:" << right[2] << ", "
    << ":D:right[3]:" << right[3] << ", "
              << std::endl;
    std::valarray<int> foo (12);
    for (int i=0; i<12; ++i) foo[i]=i;
    
    std::valarray<int> bar = foo[std::slice(2,3,4)];
    
    cout << "slice(2,3,4): ";
    for (size_t n=0; n<bar.size(); n++)
        std::cout << bar[n] << ' ';
    std::cout << endl;
              
}
*/
#endif
