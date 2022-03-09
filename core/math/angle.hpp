/* SPDX-License-Identifier: GPL-3.0 */
#pragma once
#include <core/math/const.hpp>
#include <type_traits>

static inline const float wrapAngle180N(const float angle)
{
    const float wrap = glm::mod(angle + ANG_DEGF_180, ANG_DEGF_360);
    return ((wrap < 0.0f) ? (wrap + ANG_DEGF_360) : wrap) - ANG_DEGF_180;
}

static inline const float wrapAngle180P(const float angle)
{
    return glm::mod(glm::mod(angle, ANG_DEGF_180) + ANG_DEGF_180, ANG_DEGF_180);
}

static inline const float wrapAngle360P(const float angle)
{
    return glm::mod(glm::mod(angle, ANG_DEGF_360) + ANG_DEGF_360, ANG_DEGF_360);
}

template<glm::length_t L, glm::qualifier Q>
static inline const glm::vec<L, float, Q> wrapAngle180N(const glm::vec<L, float, Q> &angles)
{
    glm::vec<L, float, Q> wrap;
    for(glm::length_t i = 0; i < L; i++)
        wrap[i] = wrapAngle180N(angles[i]);
    return wrap;
}

template<glm::length_t L, glm::qualifier Q>
static inline const glm::vec<L, float, Q> wrapAngle360P(const glm::vec<L, float, Q> &angles)
{
    glm::vec<L, float, Q> wrap;
    for(glm::length_t i = 0; i < L; i++)
        wrap[i] = wrapAngle360P(angles[i]);
    return wrap;
}
