#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int test_generate_random_stack(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 5;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  init_sorted_stack(comp, length);
  comp[1] = 3;
  comp[2] = 4;
  comp[3] = 0;
  comp[4] = 1;
  comp[5] = 2;
  shuffle(base, length, 696034213);
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base);
  free(comp);
  return (1);
}

int	test_swap_a(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 5;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  init_sorted_stack(comp, length);
  comp[5] = 1;
  comp[4] = 0;
  swap_a(base, length);
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_swap_a_small_stack(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 2;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  init_sorted_stack(comp, length);
  comp[1] = 0;
  comp[2] = 1;
  swap_a(base, length);
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_push_b(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*split;

	length = 1;
  base = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  split = base;
  push_b(base, length);
  if (*split == 1)
  	return (0);
  if (base[1] != 0)
  	return (0);
  free(base);
  base = NULL;
  return (1);
}

int	test_push_b_big_stack(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*split;

	length = 10;
  base = malloc(sizeof(uint16_t) * (length + 1));
  split = base;
  init_sorted_stack(base, length);
  push_b(base, length);
  if (*split != 9)
  	return (0);
  if (base[1] != 9)
  	return (0);
  free(base);
  base = NULL;
  return (1);
}

int	test_push_all_to_b(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;
	uint16_t	*base_split;
	uint16_t	*comp_split;

	length = 10;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  init_sorted_stack(comp, length);
  base_split = base;
  comp_split = comp;
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  if (*base_split != 0)
  	return (0);
  if (base[length ] != 0 || base[1] != 9)
  	return (0);
  *comp_split = 0;
  if (stack_cmp(comp, base, length))
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  return (1);
}

int	test_swap_b(void)
{
	uint16_t	length;
	uint16_t *base;
	uint16_t *comp;

	length = 2;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  init_sorted_stack(comp, length);
  push_b(base, length);
  push_b(base, length);
  push_b(comp, length);
  push_b(comp, length);
  swap_b(base, length);
  comp[1] = 0;
  comp[2] = 1;
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base);
  free(comp);
  base= NULL;
  comp= NULL;
  return (1);
}

int	test_swap_b_big(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 10;
  base= malloc(sizeof(uint16_t) * (length + 1));
  comp= malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  init_sorted_stack(comp, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  swap_b(base, length);
  comp[1] = 8;
  comp[2] = 9;
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_swap_b_a_not_empty(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 10;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  init_sorted_stack(comp, length);
  
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);
  push_b(comp, length);

  swap_b(base, length);
  comp[6] = 3;
  comp[7] = 4;
  if (stack_cmp(base, comp, length))
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_push_a(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*split;

	length = 1;
  base = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  split = base;
  push_b(base, length);
  push_a(base, length);
  if (*split != 1)
  	return (0);
  if (base[1] != 0)
  	return (0);
  free(base);
  base = NULL;
  return (1);
}

int	test_push_a_big_stack(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*split;

	length = 10;
  base = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  split = base;
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_a(base, length);
  if (*split != 1)
  	return (0);
  if (base[1] != 9)
  	return (0);
  free(base);
  base = NULL;
  return (1);
}

int	test_rotate_a(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 5;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  rotate_a(base, length);
  if (base[1] != 0)
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_rotate_a_small_stack(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 2;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  rotate_a(base, length);
  if (base[1] != 0)
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_rotate_a_big_stack(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 11;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  rotate_a(base, length);
  if (base[1] != 0)
   return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_rotate_a_b_not_empty(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 33;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  rotate_a(base, length);
  if (base[1] != 12)
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_rev_rotate_a_small_stack(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 2;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  rev_rotate_a(base, length);
  if (base[1] != 0)
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_rev_rotate_a_big_stack(void)
{
	uint16_t	length;
	uint16_t	*base;

	length = 10;
  base = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  rev_rotate_a(base, length);
  if (base[1] != 8)
  	return (0);
  free(base);
  base = NULL;
  return (1);
}

int	test_rotate_b_small_stack(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 2;
  base= malloc(sizeof(uint16_t) * (length + 1));
  comp= malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  push_b(base, length);
  push_b(base, length);
  rotate_b(base, length);
  if (base[1] != 0)
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int	test_rotate_b_big_stack(void)
{
	uint16_t	length;
	uint16_t	*base;

	length = 10;
  base = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  rotate_b(base, length);
  if (base[1] != 8)
  	return (0);
  free(base);
  base = NULL;
  return (1);
}

int	test_rev_rotate_b_small_stack(void)
{
	uint16_t	length;
	uint16_t	*base;

	length = 2;
	base = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  push_b(base, length);
  push_b(base, length);
  rev_rotate_b(base, length);
  if (base[1] != 0)
  	return (0);
  free(base);
  base = NULL;
  return (1);
}

int	test_rev_rotate_b_big_stack(void)
{
	uint16_t	length;
	uint16_t	*base;
	uint16_t	*comp;

	length = 10;
  base = malloc(sizeof(uint16_t) * (length + 1));
  comp = malloc(sizeof(uint16_t) * (length + 1));
  init_sorted_stack(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  push_b(base, length);
  rev_rotate_b(base, length);
  if (base[1] != 0)
  	return (0);
  free(base);
  free(comp);
  base = NULL;
  comp = NULL;
  return (1);
}

int test_is_stack_sorted(void)
{
	uint16_t	length;
	uint16_t	*stack;

	length = 10;
	stack = malloc(sizeof(uint16_t) * (length + 1));
	init_sorted_stack(stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	if (!is_stack_sorted_strict(stack, length))
		return (0);
	push_b(stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	if (is_stack_sorted_strict(stack, length))
		return (0);
	push_b(stack, length);
	push_b(stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	if (is_stack_sorted_strict(stack, length))
		return (0);
	push_b(stack, length);
	push_b(stack, length);
	push_b(stack, length);
	push_b(stack, length);
	push_b(stack, length);
	push_b(stack, length);
	push_b(stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	swap_b(stack, length);
	if (is_stack_sorted_lenient(stack, length))
		return (0);
	swap_b(stack, length);
	push_a(stack, length);
	push_a(stack, length);
	push_a(stack, length);
	push_a(stack, length);
	push_a(stack, length);
	push_a(stack, length);
	push_a(stack, length);
	push_a(stack, length);
	push_a(stack, length);
	push_a(stack, length);
	if (!is_stack_sorted_lenient(stack, length))
		return (0);
	if (!is_stack_sorted_strict(stack, length))
		return (0);
	rotate_a(stack, length);
	if (is_stack_sorted_lenient(stack, length))
		return (0);
	if (is_stack_sorted_strict(stack, length))
		return (0);
	free(stack);
	return (1);
}

int test_get_stack_diff(void)
{
	
	uint16_t	length;
	uint16_t	*stack;

	length = 10;
	stack = malloc(sizeof(uint16_t) * (length + 1));
	init_sorted_stack(stack, length);
	swap_a(stack, length);
	swap_a(stack, length);
	rotate_a(stack, length);
	rev_rotate_a(stack, length);
	push_b(stack, length);
	push_b(stack, length);
	push_b(stack, length);
	free(stack);
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
	if (verbose == true)
		ft_printf("test rotate_a success\n");
	if (!test_rotate_a_small_stack())
		return(0);
	if (verbose == true)
		ft_printf("test rotate_a_small_stack success\n");
	if (!test_rotate_a_big_stack())
		return(0);
	if (verbose == true)
		ft_printf("test rotate_a_big_stack success\n");
	if (!test_rotate_a_b_not_empty())
		return (0);
	if (verbose == true)
		ft_printf("test rotate_a_b_not_empty success\n");
	if (verbose == true)
		ft_printf("test rotate_a success\n");
	if (!test_rev_rotate_a_small_stack())
		return (0);
	if (verbose == true)
		ft_printf("test rev_rotate_a_small_stack success\n");
	if (!test_rev_rotate_a_big_stack())
		return (0);
	if (verbose == true)
		ft_printf("test rev_rotate_a_big_stack success\n");
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
