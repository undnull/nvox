/* SPDX-License-Identifier: GPL-3.0 */
#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace fs_std = std::filesystem;

namespace fs
{
using buffer_type = std::vector<unsigned char>;
using string_type = std::string;

void initialize();
void shutdown();
bool addPath(const fs_std::path &path);
bool setRoot(const fs_std::path &root);
const fs_std::path getROPath(const fs_std::path &path);
const fs_std::path getRWPath(const fs_std::path &path);
} // namespace fs

namespace fs::util
{
bool exists(const fs_std::path &path);
bool isFile(const fs_std::path &path);
bool isDirectory(const fs_std::path &path);
bool binaryRead(const fs_std::path &path, fs::buffer_type &out);
bool binaryWrite(const fs_std::path &path, const fs::buffer_type &in);
bool textRead(const fs_std::path &path, fs::string_type &out);
bool textWrite(const fs_std::path &path, const fs::string_type &in);
} // namespace fs::util
