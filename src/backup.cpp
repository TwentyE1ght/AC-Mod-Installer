#include "backup.hpp"
#include <iostream>
#include <chrono>
#include <windows.h>
#include <bit7z/bit7z.hpp>

namespace fs = std::filesystem;

void backupRoot(const fs::path& assettoRoot) {
    try {
        using namespace bit7z;
        namespace fs = std::filesystem;

        Bit7zLibrary lib{ "7z.dll" };
        BitFileCompressor compressor{ lib, BitFormat::Zip };

        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm local_tm{};
        localtime_s(&local_tm, &now_time);
        std::ostringstream oss;
        oss << std::put_time(&local_tm, "%Y-%m-%d_%H-%M-%S");
        std::string timestamp = oss.str();

        fs::path exeDir = fs::current_path();
        fs::path backupDir = exeDir / "backup" / timestamp;
        fs::create_directories(backupDir);
        fs::path archivePath = backupDir / "AssettoCorsaBackup.7z";

        std::cout << "\nBacking up files this may take a while..." << std::endl;

        compressor.compressDirectory(assettoRoot.string(), archivePath.string());

        std::cout << "\nBackup completed successfully." << std::endl;
        std::cout << "Your backup location: '" << archivePath.string() << "'" << std::endl;
    } catch (const bit7z::BitException& e) {
        std::cerr << "Backup failed: " << e.what() << std::endl;
    }
}

void backupRootDialog(const fs::path& path) {
    char userChoice = 'n';
    while (true) {
        std::cout << "Would you like to backup your Assetto Root Folder first? (y/n)" << std::endl;
        std::cin >> userChoice;
        userChoice = tolower(userChoice);
        if (userChoice == 'y') {
            backupRoot(path);
            break;
        }
        if (userChoice == 'n') {
            std::cout << "Backup skipped." << std::endl;
            break;
        }
        std::cout << "Invalid Input! Try again." << std::endl;
    }
}