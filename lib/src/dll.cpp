#include "dll.h"

bool Process::Run(int const num)
{
    str.clear();
    for (int i{}; i < num; ++i)
    {
        str.append(std::to_string(i));
    }
    return true;
}

std::string Process::Info()
{
    return str + "result";
}