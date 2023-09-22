

#include <stdint.h>
#include "array_math.h"

/***********************************************
* function name: equate_array
*
*	elementwise addition of 1d array
*	result_array = input_array
*
* inputs:
*	input_array		pointer to first operand array
*	n_elements		number of elements to operate on
* outputs:
*	result_array	pointer to result array
************************************************/
equate_array(float* input_array, uint8_t n_elements, float* result_array)
{
	for (uint8_t i = 0; i < n_elements; i++)
	{
		result_array[i] = input_array[i];
	}
}

/***********************************************
* function name: elementwise_add
* 
*	elementwise addition of 1d array
*	result_array = array_a + array_b
* 
* inputs:
*	array_a:		pointer to first operand array 
*	array_b			pointer to second operand array 
*	n_elements		number of elements to operate on
* outputs: 
*	result_array	pointer to result array 
************************************************/
elementwise_add(float* array_a, float* array_b, uint8_t n_elements, float* result_array)
{
	for (uint8_t i = 0; i < n_elements; i++)
	{
		result_array[i] = array_a[i] + array_b[i];
	}
}


/***********************************************
* function name: elementwise_subtract
*
*	elementwise subtraction of 1d array
*	result_array = array_a - array_b
*
* inputs:
*	array_a:		pointer to first operand array
*	array_b			pointer to second operand array
*	n_elements		number of elements to operate on
* outputs:
*	result_array	pointer to result array 
************************************************/
elementwise_subtract(float* array_a, float* array_b, uint8_t n_elements, float* result_array)
{
	for (uint8_t i = 0; i < n_elements; i++)
	{
		result_array[i] = array_a[i] - array_b[i];
	}
}


/***********************************************
* function name: elementwise_multiply
*
*	elementwise multiplication of 1d array
*	result_array =  array_a * array_b
*
* inputs:
*	array_a:		pointer to first operand array
*	array_b			pointer to second operand array
*	n_elements		number of elements to operate on
* outputs:
*	result_array	pointer to result array 
************************************************/
elementwise_multiply(float* array_a, float* array_b, uint8_t n_elements, float* result_array)
{
	for (uint8_t i = 0; i < n_elements; i++)
	{
		result_array[i] = array_a[i] * array_b[i];
	}
}


/***********************************************
* function name: elementwise_divide
*
*	elementwise division of 1d array
*	result_array = array_a / array_b
*
* inputs:
*	array_a:		pointer to first operand array
*	array_b			pointer to second operand array
*	n_elements		number of elements to operate on
* outputs:
*	result_array	pointer to result array
************************************************/
elementwise_divide(float* array_a, float* array_b, uint8_t n_elements, float* result_array)
{
	for (uint8_t i = 0; i < n_elements; i++)
	{
		result_array[i] = array_a[i] / array_b[i];
	}
}


/***********************************************
* function name: add_const_to_array
*
*	elementwise addition of 1d array
*	result_array = input_array + input_constant
*
* inputs:
*	input_array		pointer to first operand array
*	input_constant	constant (scalar) value
*	n_elements		number of elements to operate on
* outputs:
*	result_array	pointer to result array
************************************************/
add_const_to_array(float* input_array, float input_constant, uint8_t n_elements, float* result_array)
{
	for (uint8_t i = 0; i < n_elements; i++)
	{
		result_array[i] = input_array[i] + input_constant;
	}
}


/***********************************************
* function name: subt_const_from_array
*
*	elementwise subtraction of 1d array
*	result_array = input_array - input_constant
*
* inputs:
*	input_array		pointer to first operand array
*	input_constant	constant (scalar) value
*	n_elements		number of elements to operate on
* outputs:
*	result_array	pointer to result array
************************************************/
subt_const_from_array(float* input_array, float input_constant, uint8_t n_elements, float* result_array)
{
	for (uint8_t i = 0; i < n_elements; i++)
	{
		result_array[i] = input_array[i] - input_constant;
	}
}


/***********************************************
* function name: multiply_array_with_const
*
*	elementwise multiplication of 1d array
*	result_array = input_array * input_constant
*
* inputs:
*	input_array		pointer to first operand array
*	input_constant	constant (scalar) value
*	n_elements		number of elements to operate on
* outputs:
*	result_array	pointer to result array
************************************************/
multiply_array_with_const(float* input_array, float input_constant, uint8_t n_elements, float* result_array)
{
	for (uint8_t i = 0; i < n_elements; i++)
	{
		result_array[i] = input_array[i] * input_constant;
	}
}


/***********************************************
* function name: divide_array_by_const
*
*	elementwise division of 1d array
*	result_array = input_array / input_constant
*
* inputs:
*	input_array		pointer to first operand array
*	input_constant	constant (scalar) value
*	n_elements		number of elements to operate on
* outputs:
*	result_array	pointer to result array
************************************************/
divide_array_by_const(float* input_array, float input_constant, uint8_t n_elements, float* result_array)
{
	for (uint8_t i = 0; i < n_elements; i++)
	{
		result_array[i] = input_array[i] / input_constant;
	}
}