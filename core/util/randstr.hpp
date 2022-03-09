/* SPDX-License-Identifier: GPL-3.0 */
#pragma once
#include <core/math/compile_time.hpp>
#include <random>
#include <string>

namespace util
{
template<typename T>
static inline const std::string randstr(T &rng, size_t n)
{
    constexpr static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    constexpr static const size_t nv = math_ct::arraySize(alphanum);
    std::uniform_int_distribution<size_t> distrib(0, nv);
    std::string str = std::string(n, static_cast<char>(0));
    for(size_t i = 0; i < n; i++)
        str[i] = alphanum[distrib(rng)];
    return str;
}
} // namespace util
