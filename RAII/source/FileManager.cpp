#include "FileManager.h"
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <fstream>

FileManager::FileManager(std::string fileName)
{
    f = std::fopen(fileName.c_str(), "rw");
    if (!f)
    {
        std::string err_msg = "Failed to open file " + fileName;
        throw std::runtime_error(err_msg);
    }
    std::cout << "\nFile opened." << std::endl;
}

FileManager::~FileManager()
{
    if (f)
    {
        std::fclose(f);
        std::cout << "\nFile closed." << std::endl;
    }
}

void FileManager::getData()
{
    int n = 0;
    while (std::fscanf(f, "%d", &n) != EOF)
    {
        std::cout << n << std::endl;
    }
}

void FileManager::printProcessedFile()
{
    std::ifstream filestream(fileName);
    int n = 0;
    while (filestream >> n)
    {
        std::cout << n << "! = " << factorial(n) << std::endl;
    }
}

int FileManager::factorial(int n)
{
    if (n < 0)
        throw std::runtime_error("Negative number in the file.");
    return n == 0 ? 1 : n * factorial(n - 1);
}