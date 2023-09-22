/***************************************************************************************************************************************************
* Grid Search AKA Parameter Sweep
* Tim Vriend 9-21-2023
*
* This function is a simple optimization technique which divides each dimension into m number of equally (linearly) spaced points and evaluates all points.
* This technique might be useful for finding a good starting point(s) for more sophisticated optimization algorithms.
* Box constraints (simple upper and lower bounds) are required for this technique.
* In general, this technique is worse than other simple scanning techniques such as random search.
* If a particular dimension does not contribute much towards the objective, many evaluations are essentially wasted by this technique, while a
* random search would give more trial points to each dimension for the same number of total evaluations.
* Made using Visual Studio 2022 in C11
*
* inputs:
*	num_dimensions:		number of dimensions in feaible region/search space
*	min_bounds:			pointer to array - lower bounds of box constraints
*	max_bounds			pointer to array - upper bounds of box constraints
*	n_points_per_dim	number of steps to evaluate per dimension (total evaluations will be this to the power of n_dim)
*	evaluate()			objective function, cost function, fitness function, etc. that we wish to minimize
* outputs:
*	best_point			pointer to array - solution coordinates
*	best_eval			objective function value at best_point
*	n_eval				number of evaluations of the objective function
*************************************************************************************************************************************************/


#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <float.h>
#include "grid_search.h"
#include "array_math.h"


#define max_n_dim 100

static void init_step_size(uint16_t num_dimensions, float* min_bounds, float* max_bounds, uint16_t n_points_per_dim, float* return_step_size);


void grid_search(uint8_t n_dim, float* bounds_min, float* bounds_max, uint16_t num_points_per_dim, float evaluate(),
	float* best_point, float* best_eval, uint32_t* n_eval)
{
	float step_size[max_n_dim];
	float trial_point[max_n_dim];
	float trial_eval;
	uint16_t step_counter[max_n_dim + 1] = { 0 };
	*best_eval = FLT_MAX;
	*n_eval = 0;

	init_step_size(n_dim, bounds_min, bounds_max, num_points_per_dim, step_size);
	elementwise_add(bounds_min, step_size, n_dim, trial_point); // init trial point
	equate_array(trial_point, n_dim, best_point); // init best point

	for (uint32_t i = 0; i < (uint32_t)pow(num_points_per_dim, n_dim); i++) // loop through every possible point in search space
	{

		trial_eval = evaluate(trial_point, n_dim);
		*n_eval = *n_eval + 1;
		if (trial_eval < *best_eval)
		{
			*best_eval = trial_eval;
			equate_array(trial_point, n_dim, best_point);
		}

		step_counter[0]++;
		for (uint16_t j = 0; j < n_dim; j++) // increment and carry step counter
		{
			if (step_counter[j] >= num_points_per_dim)
			{
				step_counter[j] = 0; // reset
				step_counter[j + 1]++; // increment next dimension's counter
			}
			trial_point[j] = bounds_min[j] + (step_counter[j] + 1) * step_size[j];
		}
	}
}

static void init_step_size(uint16_t num_dimensions, float* min_bounds, float* max_bounds, uint16_t n_points_per_dim, float* return_step_size)
{
	for (uint16_t i = 0; i < num_dimensions; i++)
	{
		return_step_size[i] = (max_bounds[i] - min_bounds[i]) / (n_points_per_dim + 1);
	}
}
