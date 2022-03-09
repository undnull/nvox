/* SPDX-License-Identifier: GPL-3.0 */
#pragma once

class NonMovable {
public:
    NonMovable() = default;
    NonMovable(NonMovable &&rhs) = delete;
    NonMovable &operator=(NonMovable &&rhs) = delete;
};
