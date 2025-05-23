#include <iostream>
#include <filesystem>
#include <windows.h>
#include "backup.h"
#include "checks.h"

namespace fs = std::filesystem;

int main() {
    while (true) {
        std::string assettoRoot;
        std::cout << "What is your Assetto Root Folder?" << std::endl;
        std::getline(std::cin, assettoRoot);
        if (checkRoot(assettoRoot)) {
            std::cout << "'" << assettoRoot << "' Found!" << std::endl;
            const fs::path assettoRootFolder = assettoRoot;

            backupRootDialog(assettoRootFolder);
            break;
        }
        Sleep(500);
        std::cout << "Please try again" << std::endl;
        Sleep(500);
    }
    return 0;
}
