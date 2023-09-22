// Grid Search AKA Parameter Sweep
#include <stdio.h>
#include <stdint.h>
#include "grid_search.h"
#include "test_functions.h"

#define n_dim 3

int main()
{
	float lower_bounds[n_dim] = { -5.12, -5.12, -5.12 };
	float upper_bounds[n_dim] = { 5.12, 5.12, 5.12 };
	float result_location[n_dim];
	float result_value;
	uint32_t n_evals;
	grid_search(n_dim, lower_bounds, upper_bounds, 200, Rosenbrock_function, result_location, &result_value, &n_evals);
	printf("result: %f, %f, %f, value: %f, n_evals: %d", result_location[0], result_location[1], result_location[2], result_value, n_evals);


	return 0;
}
