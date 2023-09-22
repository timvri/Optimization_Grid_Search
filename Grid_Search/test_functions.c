#include <stdint.h>
#include <math.h>

#define PI 3.14159265358979323846

float Rosenbrock_function(float* x, uint8_t n_dim)
{
	float fx = 0;
	for (uint8_t i = 0; i < (n_dim - 1); i++)
	{
		fx = fx + 100 * pow(x[i + 1] - pow(x[i], 2), 2) + pow(1 - x[i], 2);
	}
	return fx;
}

float Rastrigin_function(float* x, uint8_t n_dim)
{
	float fx;
	const uint8_t A = 10;
	fx = A * n_dim;
	for (uint8_t i = 0; i < n_dim; i++)
	{
		fx = fx + (x[i] * x[i] - A * cos(2 * PI * x[i]));
	}
	return fx;
}

