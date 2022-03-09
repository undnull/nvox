/* SPDX-License-Identifier: GPL-3.0 */
#pragma once
#include <stddef.h>
#include <string>

namespace crc64
{
uint64_t doBinary(const void *s, size_t n);
uint64_t doString(const std::string &str);
} // namespace crc64
