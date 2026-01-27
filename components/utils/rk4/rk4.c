#include "rk4.h"

// Converted a continuous function to a discrete function
void rk4_step(const continuous_func_t f, const state_t* x, float u, float dt, state_t* x_next)
{
	state_t k1, k2, k3, k4, temp;
	f(x, u, &k1);

	temp.theta = x->theta + 0.5f * k1.theta * dt;
	temp.dtheta = x->dtheta + 0.5f * k1.dtheta * dt;
	temp.phi= x->phi + 0.5f * k1.phi * dt;
	temp.dphi = x->dphi + 0.5f * k1.dphi * dt;
	f(&temp, u, &k2);

	temp.theta = x->theta + 0.5f * k2.theta * dt;
	temp.dtheta = x->dtheta + 0.5f * k2.dtheta * dt;
	temp.phi= x->phi + 0.5f * k2.phi * dt;
	temp.dphi = x->dphi + 0.5f * k2.dphi * dt;
	f(&temp, u, &k3);

	temp.theta = x->theta + k3.theta * dt;
	temp.dtheta = x->dtheta + k3.dtheta * dt;
	temp.phi= x->phi + k3.phi * dt;
	temp.dphi = x->dphi + k3.dphi * dt;
	f(&temp, u, &k4);

	x_next->theta = x->theta + (dt / 6.0f) * (k1.theta + 2 * k2.theta + 2 * k3.theta + k4.theta);
	x_next->dtheta = x->dtheta + (dt / 6.0f) * (k1.dtheta + 2 * k2.dtheta + 2 * k3.dtheta + k4.dtheta);
	x_next->phi = x->phi + (dt / 6.0f) * (k1.phi + 2 * k2.phi + 2 * k3.phi + k4.phi);
	x_next->dphi = x->dphi + (dt / 6.0f) * (k1.dphi + 2 * k2.dphi + 2 * k3.dphi + k4.dphi);
}
