#pragma once
#include <random>
#include <string>

struct Process {
    bool Run(int num);
    [[nodiscard]] std::string Info();

private:
    std::random_device r{};
    std::default_random_engine e1{r()};
    std::string str{};
};