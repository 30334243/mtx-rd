#pragma once
#include <string>

struct Process
{
    bool Run(int num);
    [[nodiscard]] std::string Info();

private:
    std::string str{};
};