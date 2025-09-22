#include "bits/types/stack_t.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <assert.h>
#include <stdint.h>

int	swap_a(uint16_t *stack, uint16_t stack_len)
{
  uint16_t				tmp;
  uint16_t				*split;

  split = stack;
  stack++;
	assert(stack_len > 1);
	assert(*split > 1);
	assert(stack);
	
	tmp = stack[*split -1];
	stack[*split -1] =	stack[*split -2];
	stack[*split -2] = tmp;
	return (0);
}

int swap_b(uint16_t *stack, uint16_t stack_len)
{
	uint16_t tmp;
	uint16_t *split;

	split = stack;
	stack++;
	assert(stack_len > 1);
	assert(stack_len - *split > 1);
	assert(stack);

	tmp = stack[*split];
	stack[*split] = stack[*split + 1];
	stack[*split + 1] = tmp;

	return (0);
}

int swap_s(uint16_t *stack, uint16_t stack_len)
{
	swap_a(stack, stack_len);
	swap_b(stack, stack_len);
	return (0);
}

int	push_b(uint16_t *stack, uint16_t stack_len)
{
	uint16_t *split;

	split = stack;
	stack++;
	assert(stack_len > 0);
	assert(*split > 0);
	assert(stack);

	*split -= 1;
	return (0);
}

int push_a(uint16_t *stack, uint16_t stack_len)
{
	uint16_t *split;

	split = stack;
	stack++;
	assert(stack_len > 0);
	assert(*split < stack_len);
	assert(stack);

	*split += 1;
	return (0);
}

int rotate_a(uint16_t *stack, uint16_t stack_len)
{
	int	i;
	uint16_t tmp;
	uint16_t next;
	uint16_t *split;
	
	i = 0;
	split = stack;
	stack++;
	assert(stack_len > 0);
	assert(*split > 1);
	assert(stack);
	tmp = stack[*split -1];
	while (i < *split)
	{
		next = stack[i];
		stack[i] = tmp;
		tmp = next;
		i++;
	}
	return (0);
}

int rotate_b(uint16_t *stack, uint16_t stack_len)
{
	int	i;
	uint16_t tmp;
	uint16_t next;
	uint16_t *split;
	
	i = stack_len -1;
	split = stack;
	stack++;
	assert(stack_len > 0);
	assert(stack_len - *split > 1);
	assert(stack);
	tmp = stack[*split];
	while (i >= *split)
	{
		next = stack[i];
		stack[i] = tmp;
		tmp = next;
		i--;
	}
	return (0);
}

int rotate_r(uint16_t *stack, uint16_t stack_len)
{
	rotate_a(stack, stack_len);
	rotate_b(stack, stack_len);
	return (0);
}

int rev_rotate_a(uint16_t *stack, uint16_t stack_len)
{
	int	i;
	uint16_t tmp;
	uint16_t next;
	uint16_t *split;

	split = stack;
	stack++;
	i = *split -1;
	assert(stack_len > 0);
	assert(*split > 1);
	assert(stack);
	tmp = stack[0];
	while (i >= 0)
	{
		next = stack[i];
		stack[i] = tmp;
		tmp = next;
		i--;
	}
	return (0);
}

int rev_rotate_b(uint16_t *stack, uint16_t stack_len)
{
	int	i;
	uint16_t tmp;
	uint16_t next;
	uint16_t *split;

	split = stack;
	stack++;
	
	i = *split;
	assert(stack_len > 0);
	assert(stack_len - *split > 1);
	assert(stack);
	tmp = stack[stack_len - 1];
	while (i < stack_len)
	{
		next = stack[i];
		stack[i] = tmp;
		tmp = next;
		i++;
	}
	return (0);
}

int rev_rotate_r(uint16_t *stack, uint16_t stack_len)
{
	rev_rotate_a(stack, stack_len);
	rev_rotate_b(stack, stack_len);
	return (0);
}
