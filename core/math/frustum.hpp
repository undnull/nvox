/* SPDX-License-Identifier: GPL-3.0 */
#pragma once
#include <array>
#include <core/math/typedefs.hpp>

class Frustum final {
public:
    struct fplane final {
        float d;
        vector3f_t n;
        float point(const vector3f_t &v) const;
    };

public:
    void update(const matrix4f_t &projview);
    bool point(const vector3f_t &v) const;

private:
    std::array<fplane, 6> planes;
};
