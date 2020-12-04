#include "parser.h"


int main( int argc, char** argv )
{
    cout << "############################################" << endl;
    cout << "#            Monotonic Routing             #" << endl;
    cout << "############################################" << endl;

    mono monotonic;

    /////////////////////parser/////////////////////
    monotonic.parser( argc, argv );
    cout << "............parser done!!!!!!.............." << endl;

    ////////////////////////monotonic route///////////////////////
    monotonic.routing( argc, argv );
    cout << "............monotonic routing done!!!!!!.............." << endl;





    /////////////////////output/////////////////////
    monotonic.output( argc, argv );
    cout << "............output done!!!!!!.............." << endl;


    return 0;
}

