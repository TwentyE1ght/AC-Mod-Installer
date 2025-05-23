#pragma once
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void backupRoot(const fs::path& assettoRoot);
void backupRootDialog(const fs::path& path);