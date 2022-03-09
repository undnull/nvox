/* SPDX-License-Identifier: GPL-3.0 */
#include <core/fs.hpp>
#include <iterator>

static fs_std::path fs_root;
static std::vector<fs_std::path> fs_search;

void fs::initialize()
{
    fs_root = fs_std::current_path();
    fs_search.clear();
}

void fs::shutdown()
{
    fs_root.clear();
    fs_search.clear();
}

bool fs::addPath(const fs_std::path &path)
{
    // Make sure we don't add a directory twice
    for(const auto &it : fs_search) {
        if(it != path)
            continue;
        return false;
    }

    // Prepend
    fs_search.insert(fs_search.begin(), path);
    return true;
}

bool fs::setRoot(const fs_std::path &root)
{
    const fs_std::path new_root = fs_std::current_path() / root;
    if(!fs_std::is_directory(new_root) && !fs_std::create_directories(new_root))
        return false;
    fs_root = new_root;
    return true;
}

const fs_std::path fs::getROPath(const fs_std::path &path)
{
    for(const auto &it : fs_search) {
        const fs_std::path ro_path = fs_root / it / path;
        if(!fs_std::exists(ro_path))
            continue;
        return ro_path;
    }

    return fs_root / path;
}

const fs_std::path fs::getRWPath(const fs_std::path &path)
{
    return fs_root / path;
}

bool fs::util::exists(const fs_std::path &path)
{
    return fs_std::exists(fs::getROPath(path));
}

bool fs::util::isFile(const fs_std::path &path)
{
    const fs_std::path &ro_path = fs::getROPath(path);
    return fs_std::exists(ro_path) && !fs_std::is_directory(ro_path);
}

bool fs::util::isDirectory(const fs_std::path &path)
{
    const fs_std::path &ro_path = fs::getROPath(path);
    return fs_std::exists(ro_path) && fs_std::is_directory(ro_path);
}

bool fs::util::binaryRead(const fs_std::path &path, fs::buffer_type &out)
{
    std::ifstream ifile = std::ifstream(fs::getROPath(path), std::ios::binary);
    if(!ifile.is_open()) {
        out.clear();
        return false;
    }

    ifile.unsetf(std::ios::skipws);

    ifile.seekg(0, std::ios::end);
    out.resize(static_cast<size_t>(ifile.tellg()) + 1);
    ifile.seekg(0, std::ios::beg);

    out.insert(out.begin(), std::istream_iterator<char>(ifile), std::istream_iterator<char>());

    ifile.close();

    return true;
}

bool fs::util::binaryWrite(const fs_std::path &path, const fs::buffer_type &in)
{
    std::ofstream ofile = std::ofstream(fs::getRWPath(path), std::ios::binary);
    if(!ofile.is_open()) {
        return false;
    }

    ofile.write(reinterpret_cast<const char *>(in.data()), in.size());
    ofile.close();

    return true;
}

bool fs::util::textRead(const fs_std::path &path, fs::string_type &out)
{
    std::ifstream ifile = std::ifstream(fs::getROPath(path));
    if(!ifile.is_open()) {
        out.clear();
        return false;
    }

    ifile.seekg(0, std::ios::end);
    out.resize(static_cast<size_t>(ifile.tellg()) + 1, char(0));
    ifile.seekg(0, std::ios::beg);

    out.assign(std::istreambuf_iterator<char>(ifile), std::istreambuf_iterator<char>());

    ifile.close();

    return true;
}

bool fs::util::textWrite(const fs_std::path &path, const fs::string_type &in)
{
    std::ofstream ofile = std::ofstream(fs::getRWPath(path));
    if(!ofile.is_open()) {
        return false;
    }

    ofile << in << std::endl;
    ofile.close();

    return true;
}
