#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "FileManager.h"

int main()
{
    try
    {
        FileManager file("testFile.txt");
        //file.getData();
        file.printProcessedFile();
    }
    catch (std::exception &e)
    {
        std::cout << "\nException caught: " << e.what() << std::endl;
        std::cout << "We no longer have access to the file handle." << std::endl;
    }

    return 0;
}