#include "push_swap.h"
#include <assert.h>
#include <stdint.h>

int	swap_a(t_stack stack, uint16_t stack_len)
{
  uint16_t				tmp;
	
	assert(stack_len > 1);
	assert(stack.split > 1);
	assert(stack.arr);
	
	tmp = stack.arr[stack.split -1];
	stack.arr[stack.split -1] =	stack.arr[stack.split -2];
	stack.arr[stack.split -2] = tmp;
	return (0);
}

int	push_b(t_stack *stack, uint16_t stack_len)
{
	assert(stack_len > 0);
	assert(stack->split > 0);
	assert(stack->arr);

	stack->split--;
	return (0);
}
