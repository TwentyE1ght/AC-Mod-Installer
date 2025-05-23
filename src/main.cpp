#include <iostream>
#include <filesystem>
#include <fstream>
#include <windows.h>
#include <bit7z/bitfileextractor.hpp>

namespace fs = std::filesystem;

bool checkPath(std::string path) {
    const fs::path root = path;
    const std::string acPath = path.append("\\AssettoCorsa.exe");
    const fs::path acRoot = acPath;

    if (root.empty()) {
        std::cerr << "File path was not entered" << std::endl;
        return false;
    }
    if (!fs::exists(root)) {
        std::cerr << "Directory does not exist" << std::endl;
        return false;
    }
    if (!fs::is_directory(root)) {
        std::cerr << "File is not a directory" << std::endl;
        return false;
    }
    if (!fs::exists(acRoot)) {
        std::cerr << "Not an Assetto Corsa root folder" << std::endl;
        return false;
    }
    return true;
}

int main() {
    while (true) {
        std::string assettoRoot;
        std::cout << "What is your Assetto Root Folder?" << std::endl;
        std::getline(std::cin, assettoRoot);
        if (checkPath(assettoRoot)) {
            std::cout << assettoRoot << " Found!" << std::endl;
            break;
        }
        Sleep(300);
        std::cout << "Please try again" << std::endl;
        Sleep(300);
    }
    return 0;
}
