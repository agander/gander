
#include <iostream>
#include <iostream>
#include <stdexcept>
#include "general.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::size_t;

int main( int arg_count, char **arg_list )
{
    size_t res( -1 );
    try
    {
        auto prog( arg_list[0] );
        cout << prog << ":" << __func__ << "(): starts..." << endl;
        cout << "time_seed(): " << time_seed() << endl;
        res = 0;
    }
    catch( const std::exception & error)
    {
        cerr << "*** ERROR: " << error.what() << endl;
    }

    return res;
}


