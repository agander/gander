#include <cstring>
#include <iostream>
#include <limits>

//  VERSION % 100 is the patch level
//  VERSION / 100 % 1000 is the minor version
//  VERSION / 100000 is the major version

#ifndef VERSION
#define VERSION 000002
#endif
//! \remarks Calculates and then displays the length of some characters to std::cout.
//!          It chooses to read from argv[1] if argc > 1.
//! \return 0

int main( int argc, char **argv )
{
    if( argc > 1 )
        std::cout << std::strlen( *(argv+1) );
    else
    {
        size_t bytes_read = 0;
        while( std::cin.ignore( ) )
        {
            bytes_read += std::cin.gcount( );
            //DbgOutput()(__FILE__, __PRETTY_FUNCTION__, __LINE__);
            DbgOutput()(__FILE__, __func__, __LINE__);
        }
        std::cout << bytes_read;
    }
    return 0;
}

