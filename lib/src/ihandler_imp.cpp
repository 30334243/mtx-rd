#include "ihandler_imp.h"

std::string IHandlerImp::Processing(int const num) {
    if (process.Run(num)) {
        return process.Info();
    }
    return "";
}