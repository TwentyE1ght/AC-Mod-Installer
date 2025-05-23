#ifndef CHECKS_H
#define CHECKS_H

#include <filesystem>

namespace fs = std::filesystem;

bool checkRoot(std::string path) {
    const fs::path acRoot = path;
    try {
        const std::string acExe = path.append("\\AssettoCorsa.exe");
        const fs::path acExePath = acExe;
        if (!exists(acExePath)) {
            throw std::invalid_argument("is not a root folder or does not exist.");
        }
        return true;
    } catch (const std::exception &e) {
        std::cerr << "'" << fs::path(acRoot).string() << "' " << e.what() << std::endl;
        return false;
    }
}

#endif //CHECKS_H
