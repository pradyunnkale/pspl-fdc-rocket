#pragma once

#include "dynamics.h"

typedef void (*continuous_func_t)(const state_t* state, float input, state_t* dstate_dt);

void rk4_step(const continuous_func_t f, const state_t* x, float u, float dt, state_t* x_next);
