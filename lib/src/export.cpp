#include "dll.h"
#include "ihandler_imp.h"

extern "C" {
__declspec(dllexport) void* create_handler() {
    return new(std::nothrow) IHandlerImp{};
}

__declspec(dllexport) void free_handler(void* h) {
    delete (static_cast<IHandlerImp*>(h));
}
}