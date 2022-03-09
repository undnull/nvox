/* SPDX-License-Identifier: GPL-3.0 */
#pragma once
#include <core/math/typedefs.hpp>

namespace wts
{
static inline const vector3f_t worldToDevice(const matrix4f_t &matrix, const vector3f_t &world)
{
    // WC -> NDC
    const vector4f_t clip = matrix * vector4f_t(world, 1.0f);
    return vector3f_t(clip.x, clip.y, clip.z) / clip.w;
}

static inline const vector2f_t deviceToScreen(const vector3f_t &device, const vector2f_t &screen)
{
    // NDC -> SC
    return 0.5f * screen * (1.0f + vector2f_t(device.x, -device.y));
}

static inline const vector2f_t worldToScreen(const matrix4f_t &matrix, const vector2f_t &screen, const vector3f_t &world)
{
    // WC -> NDC -> SC
    return wts::deviceToScreen(wts::worldToDevice(matrix, world), screen);
}
} // namespace wts
