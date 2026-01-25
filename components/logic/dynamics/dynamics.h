#pragma once

#include <stdint.h>
#include <stddef.h>

typedef void (*dynamics_step_func_t)(float* state, const float* input, float dt);

// ------------------------
// Discrete Linear Dynamics
// ------------------------
void linear_discrete_step(float* state, const float* input, float dt);

// ------------------------
// Discrete Nonlinear Dynamics
// ------------------------
void nonlinear_discrete_step(float* state, const float* input, float dt);

void dynamics_set_step(dynamics_step_func_t func);
extern dynamics_step_func_t dynamics_step;
