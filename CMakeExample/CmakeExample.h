// DataStructures_Algorithms_Cpp.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <string_view>
using std::string, std::string_view, std::cout, std::endl;


static uint32_t alloc = 0;
void* operator new (size_t s)
{
    alloc++;
    std::cout << "allocated " << s << std::endl;
    return malloc(s);
}


// TODO: Reference additional headers your program requires here.
