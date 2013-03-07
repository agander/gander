
#include <string>
#include "boost/lexical_cast.hpp"
#include <iostream>
#include <glibmm.h>
#include <exception>

namespace some_names
{
using boost::numeric_cast;
using boost::lexical_cast;
using boost::bad_lexical_cast;
using std::endl;
using std::cout;
using std::cin;
using std::endl;
using std::string;
}

int main( int argc, char *argv[] )
{
    using namespace some_names;
    //! \note Using Glib::getenv so require Glib::init()
    Glib::init();
    //! \note Define a counter. May be reset later, depending upon a program arguement.
    long serialStart = 1;
    //long serialCount = 1;
    //! \note Define the output data delimiter. May be amended later.
    std::string out_delimiter = "|";
    //! \note If the 1st program arguement is available then attempt to convert
    //!       it to a number.
    if( argc > 1 )
    {
        try
        {
            serialStart = boost::lexical_cast< long >( argv[1] );
        }
        catch( const std::exception &e )
        {
            std::cerr << "!!! WARNING - Attempt to use argv[1] as a "
                      << "starting value for the counter failed." << endl
                      << "Error is: ["
                      << e.what() << "]" << std::endl
                      << "1 will be used."
                      << std::endl;
            //! \note Reset serialStart to 1, just to be sure it hasnt been changed.
            serialStart = 1;
        }
    }

    //! \note Get the ${OUTPUT_DELIMITER} if found.
    bool have_outdelim_var(false);
    out_delimiter = Glib::getenv("OUTPUT_DELIMITER", have_outdelim_var);
    //! \note If failed to get it, have_outdelim_var == false, then reset out_delimiter to default of "|".
    if( ! have_outdelim_var )
        out_delimiter = "|";

    //! \note Define a large string to read stdin into
    std::string line;
    line.reserve(1024000);
    while( getline(std::cin, line))
    {
        //! \note Spit out the counter, then delimiter, the data and a new line.
        std::cout << serialStart << out_delimiter << line << std::endl;
        ++serialStart;
    }

    return std::cout.bad();
}
