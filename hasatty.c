
#include <unistd.h>

int main( int arg_count, char **arg_list )
{
    int fildes = 0;
    if( arg_count > 1 )
        fildes = atoi( arg_list[1] );
    return (isatty( fildes )) ? 0 : 1;
}

