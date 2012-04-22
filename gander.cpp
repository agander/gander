//$Id$
#include "gander.hpp"
#include <stdexcept>


int main(int argc, char** argv)
{

   try
   {
      mylogin mylogin;
      mylogin.slurp( );

    }
    catch(std::exception & er)
    {
        std::cerr << "*** ERROR: " << er.what() << "\n";
        return -1;
    }

    return std::cout.bad();

}

