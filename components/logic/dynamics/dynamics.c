#include "dynamics.h"

// Change this when changing the type of dynamics you want to use
dynamics_step_func_t dynamics_step = linear_discrete_step;

void dynamics_set_step(dynamics_step_func_t func)
{
	dynamics_step = func;
}

// ------------------------
// Discrete Linear Dynamics
// ------------------------
void linear_discrete_step(float* state, const float* input, float dt)
{

}

// ------------------------
// Discrete Nonlinear Dynamics
// ------------------------
void nonlinear_discrete_step(float* state, const float* input, float dt)
{

}

