#include "checks.hpp"
#include <iostream>
#include <filesystem>
#include <windows.h>

double getRootSize(const fs::path &root) {
    std::cout << "\nGetting root size..." << std::endl;
    uintmax_t totalSize = 0;
    for (const auto& entry : fs::recursive_directory_iterator(root)) {
        if (fs::is_regular_file(entry.status())) {
            totalSize += fs::file_size(entry.path());
        }
    }
    return static_cast<double>(totalSize);
}

bool checkRoot(std::string path) {
    const fs::path acRoot = path;
    try {
        const std::string acExe = path.append("\\AssettoCorsa.exe");
        const fs::path acExePath = acExe;
        if (!exists(acExePath)) {
            throw std::invalid_argument("is not a root folder or does not exist.");
        }
        double totalSize = getRootSize(acRoot);
        double totalSizeGB = totalSize / (1024 * 1024 * 1024);
        std::cout << "Total size: " << std::fixed << std::setprecision(1) << totalSizeGB << " GB" << std::endl;
        Sleep(500);
        return true;
    } catch (const std::exception &e) {
        std::cerr << "'" << fs::path(acRoot).string() << "' " << e.what() << std::endl;
        return false;
    }
}