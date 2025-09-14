#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int test_generate_random_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 5;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  init_sorted_stack(&comp, length);
  comp.arr[0] = 3;
  comp.arr[1] = 4;
  comp.arr[2] = 0;
  comp.arr[3] = 1;
  comp.arr[4] = 2;
  shuffle(base.arr, length, 696034213);
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_swap_a(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 5;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  init_sorted_stack(&comp, length);
  comp.arr[4] = 1;
  comp.arr[3] = 0;
  swap_a(&base, length);
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_swap_a_small_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 2;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  init_sorted_stack(&comp, length);
  comp.arr[0] = 0;
  comp.arr[1] = 1;
  swap_a(&base, length);
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_push_b(void)
{
	uint16_t	length;
	t_stack		base;

	length = 1;
  base.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  push_b(&base, length);
  if (base.split == 1)
  	return (0);
  if (base.arr[0] != 0)
  	return (0);
  free(base.arr);
  base.arr = NULL;
  return (1);
}

int	test_push_b_big_stack(void)
{
	uint16_t	length;
	t_stack		base;

	length = 10;
  base.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  push_b(&base, length);
  if (base.split != 9)
  	return (0);
  if (base.arr[0] != 9)
  	return (0);
  free(base.arr);
  base.arr = NULL;
  return (1);
}

int	test_push_all_to_b(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 10;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  init_sorted_stack(&comp, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  if (base.split != 0)
  	return (0);
  if (base.arr[length -1] != 0 || base.arr[0] != 9)
  	return (0);
  comp.split = 0;
  if (stack_cmp(comp, base, length))
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  return (1);
}

int	test_swap_b(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 2;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  init_sorted_stack(&comp, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&comp, length);
  push_b(&comp, length);
  swap_b(&base, length);
  comp.arr[0] = 0;
  comp.arr[1] = 1;
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_swap_b_big(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 10;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  init_sorted_stack(&comp, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  swap_b(&base, length);
  comp.arr[0] = 8;
  comp.arr[1] = 9;
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_swap_b_a_not_empty(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 10;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  init_sorted_stack(&comp, length);
  
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);
  push_b(&comp, length);

  swap_b(&base, length);
  comp.arr[5] = 3;
  comp.arr[6] = 4;
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_push_a(void)
{
	uint16_t	length;
	t_stack		base;

	length = 1;
  base.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  push_b(&base, length);
  push_a(&base, length);
  if (base.split != 1)
  	return (0);
  if (base.arr[0] != 0)
  	return (0);
  free(base.arr);
  base.arr = NULL;
  return (1);
}

int	test_push_a_big_stack(void)
{
	uint16_t	length;
	t_stack		base;

	length = 10;
  base.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_a(&base, length);
  if (base.split != 1)
  	return (0);
  if (base.arr[0] != 9)
  	return (0);
  free(base.arr);
  base.arr = NULL;
  return (1);
}

int	test_rotate_a(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 5;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  rotate_a(&base, length);
  if (base.arr[0] != 0)
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_rotate_a_small_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 2;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  rotate_a(&base, length);
  if (base.arr[0] != 0)
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_rotate_a_big_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 11;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  rotate_a(&base, length);
  if (base.arr[0] != 0)
   return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_rotate_a_b_not_empty(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 33;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  rotate_a(&base, length);
  if (base.arr[0] != 12)
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_rev_rotate_a_small_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 2;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  rev_rotate_a(&base, length);
  if (base.arr[0] != 0)
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_rev_rotate_a_big_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 10;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  rev_rotate_a(&base, length);
  if (base.arr[0] != 8)
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_rotate_b_small_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 2;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  rotate_b(&base, length);
  if (base.arr[0] != 0)
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_rotate_b_big_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 10;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  rotate_b(&base, length);
  if (base.arr[0] != 8)
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_rev_rotate_b_small_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 2;
	base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  rev_rotate_b(&base, length);
  if (base.arr[0] != 0)
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int	test_rev_rotate_b_big_stack(void)
{
	uint16_t	length;
	t_stack		base;
	t_stack		comp;

	length = 10;
  base.arr = malloc(sizeof(uint16_t) * length);
  comp.arr = malloc(sizeof(uint16_t) * length);
  init_sorted_stack(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  push_b(&base, length);
  rev_rotate_b(&base, length);
  if (base.arr[0] != 0)
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int test_is_stack_sorted(void)
{
	uint16_t	length;
	t_stack		stack;

	length = 10;
	stack.arr = malloc(sizeof(uint16_t) * length);
	init_sorted_stack(&stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	if (!is_stack_sorted_strict(stack, length))
		return (0);
	push_b(&stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	if (is_stack_sorted_strict(stack, length))
		return (0);
	push_b(&stack, length);
	push_b(&stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	if (is_stack_sorted_strict(stack, length))
		return (0);
	push_b(&stack, length);
	push_b(&stack, length);
	push_b(&stack, length);
	push_b(&stack, length);
	push_b(&stack, length);
	push_b(&stack, length);
	push_b(&stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	swap_b(&stack, length);
	if (is_stack_sorted_lenient(stack, length))
		return (0);
	swap_b(&stack, length);
	push_a(&stack, length);
	push_a(&stack, length);
	push_a(&stack, length);
	push_a(&stack, length);
	push_a(&stack, length);
	push_a(&stack, length);
	push_a(&stack, length);
	push_a(&stack, length);
	push_a(&stack, length);
	push_a(&stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	if (!is_stack_sorted_strict(stack, length))
		return (0);
	rotate_a(&stack, length);
	if (is_stack_sorted_lenient(stack, length))
		return (0);
	if (is_stack_sorted_strict(stack, length))
		return (0);
	free(stack.arr);
	return (1);
}

int test_get_stack_diff(void)
{
	
	uint16_t	length;
	t_stack		stack;

	length = 10;
	stack.arr = malloc(sizeof(uint16_t) * length);
	init_sorted_stack(&stack, length);
	swap_a(&stack, length);
	swap_a(&stack, length);
	rotate_a(&stack, length);
	rev_rotate_a(&stack, length);
	push_b(&stack, length);
	push_b(&stack, length);
	push_b(&stack, length);
	free(stack.arr);
	return (1);
}

int start_all_tests(bool verbose)
{
	if (!test_generate_random_stack())
		return (0);
	if (verbose == true)
		ft_printf("test generate random stack success\n");
	if (!test_swap_a())
		return (0);
	if (!test_swap_a_small_stack())
		return (0);
	if (verbose == true)
		ft_printf("test swap a success\n");
	if (!test_push_b())
		return (0);
	if (!test_push_b_big_stack())
		return (0);
	if (!test_push_all_to_b())
		return (0);
	if (!test_swap_b())
		return (0);
	if (!test_swap_b_big())
		return (0);
	if (!test_swap_b_a_not_empty())
		return (0);
	if (verbose == true)
		ft_printf("test push_b success\n");
	if (!test_push_a())
		return (0);
	if (!test_push_a_big_stack())
		return (0);
	if (verbose == true)
		ft_printf("test push_a success\n");
	if (!test_rotate_a())
		return(0);
	if (!test_rotate_a_small_stack())
		return(0);
	if (!test_rotate_a_big_stack())
		return(0);
	if (!test_rotate_a_b_not_empty())
		return (0);
	if (verbose == true)
		ft_printf("test rotate_a success\n");
	if (!test_rev_rotate_a_small_stack())
		return (0);
	if (!test_rev_rotate_a_big_stack())
		return (0);
	if (verbose == true)
		ft_printf("test_rev_rotate_a success\n");
	if (!test_rotate_b_small_stack())
		return (0);
	if (!test_rotate_b_big_stack())
		return (0);
	if (verbose == true)
		ft_printf("test_rotate_b success\n");
	if (!test_rev_rotate_b_small_stack())
		return (0);
	if (!test_rev_rotate_b_big_stack())
		return (0);
	if (verbose == true)
		ft_printf("test_rev_rotate b success\n");
	if (!test_is_stack_sorted())
		return (0);
	if (verbose == true)
		ft_printf("test_is_stack_sorted success\n");
	if (!test_get_stack_diff())
		return (0);
	if (verbose == true)
		ft_printf("test get_stack_diff success\n");
	return (1);
}
