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

void print_stacks(const t_stack stack, uint16_t stack_len)
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
  while (i < stack_len)
  {
    ft_printf("%u", stack.arr[i]);
    i++;
  }
}

void init_sorted_stack(t_stack *stack, uint16_t stack_len)
{
  int i;

  i = stack_len;
  while (i > 0)
  {
    stack->arr[stack_len - i] = i - 1;
    i--;
  }
  stack->diff = 0;
  stack->split = stack_len;
}

int stack_cmp(t_stack ref, t_stack other, uint16_t stack_len)
{
  uint16_t i;

  i = 0;
  if (ref.diff != other.diff)
    return (1);
  if (ref.split != other.split)
    return (1);
  while (i < stack_len)
  {
    if (ref.arr[i] != other.arr[i])
      return (1);
    i++;
  }
  return (0);
}
