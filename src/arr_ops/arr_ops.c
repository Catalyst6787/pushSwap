#include "bits/types/stack_t.h"
#include "push_swap.h"
#include <assert.h>
#include <stdint.h>

int	swap_a(t_stack *stack, uint16_t stack_len)
{
  uint16_t				tmp;
	
	assert(stack_len > 1);
	assert(stack->split > 1);
	assert(stack->arr);
	
	tmp = stack->arr[stack->split -1];
	stack->arr[stack->split -1] =	stack->arr[stack->split -2];
	stack->arr[stack->split -2] = tmp;
	return (0);
}

int swap_b(t_stack *stack, uint16_t stack_len)
{
	uint16_t tmp;

	assert(stack_len > 1);
	assert(stack_len - stack->split > 1);
	assert(stack->arr);

	tmp = stack->arr[stack->split];
	stack->arr[stack->split] = stack->arr[stack->split + 1];
	stack->arr[stack->split + 1] = tmp;

	return (0);
}

int swap_s(t_stack *stack, uint16_t stack_len)
{
	swap_a(stack, stack_len);
	swap_b(stack, stack_len);
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

int push_a(t_stack *stack, uint16_t stack_len)
{
	assert(stack_len > 0);
	assert(stack->split < stack_len);
	assert(stack->arr);

	stack->split++;
	return (0);
}

int rotate_a(t_stack *stack, uint16_t stack_len)
{
	int	i;
	uint16_t tmp;
	uint16_t next;
	
	i = 0;
	assert(stack_len > 0);
	assert(stack->split > 1);
	assert(stack->arr);
	tmp = stack->arr[stack->split -1];
	while (i < stack->split)
	{
		next = stack->arr[i];
		stack->arr[i] = tmp;
		tmp = next;
		i++;
	}
	return (0);
}

int rotate_b(t_stack *stack, uint16_t stack_len)
{
	int	i;
	uint16_t tmp;
	uint16_t next;
	
	i = stack_len -1;
	assert(stack_len > 0);
	assert(stack_len - stack->split > 1);
	assert(stack->arr);
	tmp = stack->arr[stack->split];
	while (i >= stack->split)
	{
		next = stack->arr[i];
		stack->arr[i] = tmp;
		tmp = next;
		i--;
	}
	return (0);
}

int rotate_r(t_stack *stack, uint16_t stack_len)
{
	rotate_a(stack, stack_len);
	rotate_b(stack, stack_len);
	return (0);
}

int rev_rotate_a(t_stack *stack, uint16_t stack_len)
{
	int	i;
	uint16_t tmp;
	uint16_t next;
	
	i = stack->split -1;
	assert(stack_len > 0);
	assert(stack->split > 1);
	assert(stack->arr);
	tmp = stack->arr[0];
	while (i >= 0)
	{
		next = stack->arr[i];
		stack->arr[i] = tmp;
		tmp = next;
		i--;
	}
	return (0);
}

int rev_rotate_b(t_stack *stack, uint16_t stack_len)
{
	int	i;
	uint16_t tmp;
	uint16_t next;
	
	i = stack->split;
	assert(stack_len > 0);
	assert(stack_len - stack->split > 1);
	assert(stack->arr);
	tmp = stack->arr[stack_len - 1];
	while (i < stack_len)
	{
		next = stack->arr[i];
		stack->arr[i] = tmp;
		tmp = next;
		i++;
	}
	return (0);
}

int rev_rotate_r(t_stack *stack, uint16_t stack_len)
{
	rev_rotate_a(stack, stack_len);
	rev_rotate_b(stack, stack_len);
	return (0);
}
