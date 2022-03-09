/* SPDX-License-Identifier: GPL-3.0 */
#pragma once
#include <core/math/typedefs.hpp>

constexpr static const float ANG_DEGF_0 = glm::radians(0.0f);
constexpr static const float ANG_DEGF_89 = glm::radians(89.0f);
constexpr static const float ANG_DEGF_90 = glm::radians(90.0f);
constexpr static const float ANG_DEGF_180 = glm::radians(180.0f);
constexpr static const float ANG_DEGF_360 = glm::radians(360.0f);

constexpr static const vector2f_t VECTOR2F_ZERO = { 0.0f, 0.0f };
constexpr static const vector3f_t VECTOR3F_ZERO = { 0.0f, 0.0f, 0.0f };
constexpr static const vector4f_t VECTOR4F_ZERO = { 0.0f, 0.0f, 0.0f, 0.0f };

constexpr static const vector2f_t VECTOR2F_IDENT = { 1.0f, 1.0f };
constexpr static const vector3f_t VECTOR3F_IDENT = { 1.0f, 1.0f, 1.0f };
constexpr static const vector4f_t VECTOR4F_IDENT = { 1.0f, 1.0f, 1.0f, 1.0f };
constexpr static const matrix4f_t MATRIX4F_IDENT = glm::identity<matrix4f_t>();
constexpr static const quaternf_t QUATERNF_IDENT = glm::identity<quaternf_t>();

constexpr static const vector3f_t VECTOR3F_FORWARD = { 0.0f, 0.0f, -1.0f };
constexpr static const vector3f_t VECTOR3F_RIGHT = { 1.0f, 0.0f, 0.0f };
constexpr static const vector3f_t VECTOR3F_UP { 0.0f, 1.0f, 0.0f };
