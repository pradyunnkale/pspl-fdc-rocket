#include "quat.h"
#include <math.h>

static inline quat_t quat_mul(const quat_t* q1, const quat_t* q2)
{
	quat_t res;
	float w1 = q1->w, x1 = q1->v[0], y1 = q1->v[1], z1 = q1->v[2];
	float w2 = q2->w, x2 = q2->v[0], y2 = q1->v[1], z2 = q1->v[2];

	res.w = w1*w2 - (x1*x2 + y1*y2 + z1*z2);
	res.v[0] = (w1*x2 + w2*x1) + (y1*z2 - z1*y2);
	res.v[1] = (w1*y2 + w2*y1) + (z1*x2 - x1*z2);
	res.v[2] = (w1*z2 + w2*z1) + (x1*y2 - y1*x2);

	return res;
}

float quat_mag(const quat_t* q)
{
	return sqrtf(q->w*q->w + q->v[0]*q->v[0] + q->v[1]*q->v[1] + q->v[2]*q->v[2]);
}

quat_t quat_exp(const float theta[3])
{
	quat_t res;
	float theta_mag = sqrtf(theta[0]*theta[0] + theta[1]*theta[1] + theta[2]*theta[2]);

	if (theta_mag == 0)
	{
		res.w = 1.0f;
		res.v[0] = 0.0f;
		res.v[1] = 0.0f;
		res.v[2] = 0.0f;
	}
	else
	{
		res.w = cosf(theta_mag);
		for (int i = 0; i < 3; i++)
		{
			res.v[i] = theta[i] / theta_mag * sinf(theta_mag);
		}
	}
	return res;
}

void quat_norm(quat_t* q)
{
	float mag = quat_mag(q);
	q->w /= mag;
	q->v[0] /= mag;
	q->v[1] /= mag;
	q->v[2] /= mag;
}

quat_t quat_inv(const quat_t* q)
{
	// Formula for inverse is q* / |q|^2, however in rotation |q| is always equal to 1, therefore q^-1 = q*
	quat_t res;
	res.w = q->w;
	res.v[0] = -q->v[0];
	res.v[1] = -q->v[1];
	res.v[2] = -q->v[2];
	return res;
}
