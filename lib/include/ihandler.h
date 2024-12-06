#pragma once

#include <string>

class IHandler {
public:
    virtual ~IHandler() = default;
    virtual [[nodiscard]] std::string Processing(int const num) = 0;
};