#pragma once

#include "ihandler.h"
#include "dll.h"

class IHandlerImp : public IHandler {
public:
    IHandlerImp() = default;
    ~IHandlerImp() override = default;
    [[nodiscard]] std::string Processing(int const num) override;

private:
    Process process{};
};