#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h> 
#include <ctime> 
#pragma comment(lib, "urlmon.lib")
using namespace std;

int main()
{
    string destFolder = "D:/1/";
    string srcURL = "https://cataas.com/cat";

    while (true)
    {
        if (_kbhit() && _getch() == '\r')
        {

            time_t now = time(0);
            tm ltm;
            localtime_s(&ltm, &now);
            string destFile = destFolder + "image_" + to_string(ltm.tm_sec) + ".jpg";


            if (S_OK == URLDownloadToFileA(NULL, srcURL.c_str(), destFile.c_str(), 0, NULL))
            {
                cout << "Saved to " << destFile << "\n";
            }
            else
            {
                cout << "Failed to download image.\n";
            }
        }
    }

    return 0;
}