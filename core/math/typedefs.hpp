/* SPDX-License-Identifier: GPL-3.0 */
#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

using vector2f_t = glm::vec<2, float, glm::packed_highp>;
using vector3f_t = glm::vec<3, float, glm::packed_highp>;
using vector4f_t = glm::vec<4, float, glm::packed_highp>;
using matrix4f_t = glm::mat<4, 4, float, glm::packed_highp>;
using quaternf_t = glm::qua<float, glm::packed_highp>;

using vector2d_t = glm::vec<2, double, glm::packed_highp>;
using vector3d_t = glm::vec<3, double, glm::packed_highp>;
using vector4d_t = glm::vec<4, double, glm::packed_highp>;
