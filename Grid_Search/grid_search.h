#ifndef GRID_SEARCH_H
#define GRID_SEARCH_H

#include <stdint.h>

void grid_search(uint8_t n_dim, float* bounds_min, float* bounds_max, uint16_t num_points_per_dim, float evaluate(),
	float* best_point, float* best_eval, uint32_t* n_eval);


#endif