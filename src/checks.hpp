#pragma once
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

double getRootSize(const fs::path &root);
bool checkRoot(std::string path);