#ifndef BACKUP_H
#define BACKUP_H

#include <iostream>
#include <filesystem>
#include <windows.h>
#include <bit7z/bit7z.hpp>

namespace fs = std::filesystem;

// Backup
double getRootSize(const fs::path &root) {
    std::cout << "\nGetting root size..." << std::endl;
    uintmax_t totalSize = 0;
    for (const auto& entry : fs::recursive_directory_iterator(root)) {
        if (fs::is_regular_file(entry.status())) {
            totalSize += fs::file_size(entry.path());
        }
    }
    const auto totalSizeB = static_cast<double>(totalSize);
    return totalSizeB;
}

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

        double totalSize = getRootSize(assettoRoot);
        double totalSizeGB = totalSize / (1024 * 1024 * 1024);
        std::cout << "Total size: " << std::fixed << std::setprecision(1) << totalSizeGB << " GB" << std::endl;
        Sleep(500);
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
        std::cout << "Would you like to backup your Assetto Root Folder first? (y or n)" << std::endl;
        std::cin >> userChoice;
        if (userChoice == 'y' || userChoice == 'Y') {
            backupRoot(path);
            break;
        }
        if (userChoice == 'n' || userChoice == 'N') {
            std::cout << "Backup skipped." << std::endl;
            break;
        }
        std::cout << "Invalid Input! Try again." << std::endl;
    }
}

#endif //BACKUP_H
