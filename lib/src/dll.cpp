#include "dll.h"

bool Process::Run(int const num) {
    str.clear();
    for (int i{}; i < num; ++i) {
        std::uniform_int_distribution<int> uniform_dist(1, 100);
        auto const val{uniform_dist(e1)};
        if (val % 2) {
            return false;
        }
        str.append(std::to_string(val));
    }
    return true;
}

std::string Process::Info() {
    return str;
}