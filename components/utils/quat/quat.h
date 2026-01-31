#pragma once

typedef struct
{
	float w;
	float v[3];
}
quat_t;

static inline quat_t quat_mul(const quat_t* q1, const quat_t* q2); // NON-COMMUTATIVE!!!!!
quat_t quat_inv(const quat_t* q);
quat_t quat_exp(const quat_t* q);

// Verification for mag == 1
float quat_mag(const quat_t* q); 
void quat_norm(quat_t* q);
