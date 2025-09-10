#include "../libft/includes/ft_printf.h"
#include "push_swap.h"
#include <stdint.h>

void print_arr(const uint16_t *arr, const uint16_t size)
{
  uint16_t i;

  i = 0;
  printf("array: ");
  while (i < size)
    printf("%u", arr[i++]);
  printf("\n");
}

void print_stacks(const t_stack stack)
{
  int i;

  i = stack.split -1;
  ft_printf("stack_a:\n");
  while (i >= 0)
  {
    ft_printf("%u", stack.arr[i]);
    i--;
  }
  i = stack.split;
  ft_printf("\nstack_b:\n");
  while (i < STACK_LEN)
  {
    ft_printf("%u", stack.arr[i]);
    i++;
  }
}

void init_sorted_stack(t_stack stack)
{
  int i;

  i = STACK_LEN;
  while (i > 0)
  {
    stack.arr[STACK_LEN - i] = i - 1;
    i--;
  }
  stack.diff = 0;
  stack.split = STACK_LEN;
}
