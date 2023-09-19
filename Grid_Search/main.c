// Grid Search AKA Parameter Sweep
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <float.h>


#define n_dim 3

const float bounds_min[n_dim] = {2, 2, 2};
const float bounds_max[n_dim] = {13, 13, 13};
const uint16_t num_points_per_dim = 10;

static void init_step_size(uint16_t num_dimensions, float *min_bounds, float* max_bounds, uint16_t n_points_per_dim, float *return_step_size);
static void set_array(uint16_t array_size, float *array_to_copy, float *return_array_to_set);
static void elementwise_addition(uint16_t array_size, float* array_a, float* array_b, float* return_summed_array);
static void init_trial_point(uint16_t num_dimensions, float *min_bounds, float *step_size, float *return_trial_point);
static float evaluate(float x[2]);

int main()
{
	float step_size[n_dim] = {0};
	float trial_point[n_dim] = {0};
	float best_point[n_dim] = {0};
	float trial_eval;
	float best_eval = FLT_MAX;
	uint16_t step_counter[n_dim + 1] = {0};  

	init_step_size(n_dim, bounds_min, bounds_max, num_points_per_dim, step_size);
	init_trial_point(n_dim, bounds_min, step_size, trial_point);
	set_array(n_dim, trial_point, best_point);

	uint16_t loop_counter = 0;

	for (uint16_t i = 0; i < (uint16_t)pow(num_points_per_dim, n_dim); i++) // loop through every possible point in search space
	{
		loop_counter++;
		//////////////// eval and compare ///////////////////////
		trial_eval = evaluate(trial_point);
		if (trial_eval < best_eval)
		{
			best_eval = trial_eval;
			set_array(n_dim, trial_point, best_point);
		}
		/////////////////////////////////////////////////////////

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
	printf("best_point: %f, %f, %f \n", best_point[0], best_point[1], best_point[2]);
	return 0;
}

static void init_step_size(uint16_t num_dimensions, float *min_bounds, float *max_bounds, uint16_t n_points_per_dim, float *return_step_size)
{
	for (uint16_t i = 0; i < num_dimensions; i++)
	{
		return_step_size[i] = (max_bounds[i] - min_bounds[i]) / (num_points_per_dim + 1);
	}
}

static void elementwise_addition(uint16_t array_size, float* array_a, float* array_b, float* return_summed_array)
{
	for (uint16_t i = 0; i < array_size; i++)
	{
		return_summed_array[i] = array_a[i] + array_b[i];
	}
}

static void set_array(uint16_t array_size, float* array_to_copy, float* return_array_to_set)
{
	for (uint16_t i = 0; i < array_size; i++)
	{
		return_array_to_set[i] = array_to_copy[i];
	}
}

static void init_trial_point(uint16_t num_dimensions, float* min_bounds, float* step_size, float* return_trial_point)
{
	elementwise_addition(num_dimensions, min_bounds, step_size, return_trial_point);
}

float evaluate(float x[2])
{
	return (pow((x[0] - 2), 4) + pow(x[0] - 2 * x[1], 2)); // 4th order, 2 dimensional polynomial
}