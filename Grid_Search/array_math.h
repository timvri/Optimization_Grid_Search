#ifndef ARRAY_MATH_H
#define ARRAY_MATH_H

#include <stdint.h>

equate_array(float* input_array, uint8_t n_elements, float* result_array);
elementwise_add(float* array_a, float* array_b, uint8_t n_elements, float* result_array);
elementwise_subtract(float* array_a, float* array_b, uint8_t n_elements, float* result_array);
elementwise_multiply(float* array_a, float* array_b, uint8_t n_elements, float* result_array);
elementwise_divide(float* array_a, float* array_b, uint8_t n_elements, float* result_array);
add_const_to_array(float* input_array, float input_constant, uint8_t n_elements, float* result_array);
subt_const_from_array(float* input_array, float input_constant, uint8_t n_elements, float* result_array);
multiply_array_with_const(float* input_array, float input_constant, uint8_t n_elements, float* result_array);
divide_array_by_const(float* input_array, float input_constant, uint8_t n_elements, float* result_array);

#endif