#include "push_swap.h"
#include <stdio.h>

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
  swap_a(base, length);
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
  swap_a(base, length);
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base.arr);
  free(comp.arr);
  base.arr = NULL;
  comp.arr = NULL;
  return (1);
}

int start_all_tests(void)
{
	if (!test_generate_random_stack())
		return (0);
	printf("test generate random stack success\n");
	if (!test_swap_a())
		return (0);
	if (!test_swap_a_small_stack())
		return (0);
	printf("test swap a\n");
	return (1);
}
