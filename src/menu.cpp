#include "menu.hpp"
#include <iostream>
#include "backup.hpp"

void mainMenu(fs::path root) {
    int option = 0;
    while (option != 0) {
        std::cout << "What would you like to Install?" << std::endl;
        std::cout << "1. Essentials" << std::endl;
        std::cout << "2. Shaders + Video Settings" << std::endl;
        std::cout << "3. Controller Support" << std::endl;
        std::cout << "4. All" << std::endl;
        std::cout << "5. Custom Mod Folder (zip, rar, 7z)" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> option;
        switch (option) {
            case 1:
                std::cout << "Essentials" << std::endl;
            break;
            case 2:
                std::cout << "Shaders + Video Settings" << std::endl;
            break;
            case 3:
                std::cout << "Controller Support" << std::endl;
            break;
            case 4:
                std::cout << "All" << std::endl;
            break;
            case 5:
                std::cout << "Custom Mod Folder (zip, rar, 7z)" << std::endl;
            break;
            case 0:
                std::cout << "Exiting..." << std::endl;
            break;
            default:
                std::cout << "Invalid Option" << std::endl;
            break;
        }
    }
}