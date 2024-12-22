#include <windows.h>
#include <iostream>
#include "ihandler.h"

static constexpr int kOk{0};
static constexpr int kLoadFunctionError{2};
static constexpr int kCreateHandlerError{3};
static constexpr int kLoadLibraryError{4};
static inline std::string const kName{std::string{PROJECT_NAME} + ".dll"};

int main()
{
    auto handle = LoadLibraryA(kName.c_str());
    if (!handle)
    {
        std::cerr << "Cannot open library: " << std::endl;
        return kLoadLibraryError;
    }
    std::cout << "Load \"" << kName << "\"" << std::endl;

    auto create_handler{(void *(*)())GetProcAddress(handle, "create_handler")};
    auto free_handler{(void (*)(void *))GetProcAddress(handle, "free_handler")};
    if (nullptr == create_handler || nullptr == free_handler)
    {
        std::cerr << "Cannot load symbol" << std::endl;
        FreeLibrary(handle);
        return kLoadFunctionError;
    }

    auto process{reinterpret_cast<IHandler *>(create_handler())};
    if (!process)
    {
        return kCreateHandlerError;
    }

    for (int i{}; i < 10; ++i)
    {
        if (auto const str{process->Processing(6)}; !str.empty())
        {
            std::cout << str << "\n";
        }
    }

    return kOk;
}