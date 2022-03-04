#ifndef __cipher
#define __cipher

#include <iostream>
#include <fstream>

class File
{
    public:
    File();
    ~File();
    void decode();
    void code();

    private:
    const int shifting;
    std::ifstream fin;
    std::ofstream ret;

};

#endif