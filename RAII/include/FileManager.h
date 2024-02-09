#pragma once
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <fstream>


class FileManager
{
public:
    FileManager(std::string fileName);
    ~FileManager();
    void printProcessedFile();
    void getData();

    std::string fileName;
    FILE *f;

private:
    int factorial(int n);
};