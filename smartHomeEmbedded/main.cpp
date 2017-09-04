#include <iostream>
#include <communicationlibrary.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;

    communicationLibrary *communicationLibraryObj = new communicationLibrary();
    bool didConnectSucceed = communicationLibraryObj->connect();
    while(1)
    {
        if(didConnectSucceed != true)
        {
            break;
        }
    }

    return 0;
}
