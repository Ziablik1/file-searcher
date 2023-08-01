#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

fs::path findFileInDirectory(const std::string& directory, const std::string& targetFile);
std::vector<fs::path> listFoldersInRoot(const std::string& directory, const std::string& targetFile, fs::path& fileInRoot);
void search(const std::string& name);

#endif
