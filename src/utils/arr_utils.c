#include "push_swap.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

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
    ft_printf("|%u", stack.arr[i]);
    i--;
  }
  if (i != stack.split -1)
    ft_printf("|");
  i = stack.split;
  ft_printf("\nstack_b:\n");
  while (i < stack_len)
  {
    ft_printf("|%u", stack.arr[i]);
    i++;
  }
  if (i != stack.split)
    ft_printf("|");
  ft_printf("\n");
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
  stack->split = stack_len;
}

int stack_cmp(t_stack ref, t_stack other, uint16_t stack_len)
{
  uint16_t i;

  i = 0;
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

// returns true even if items in stack b
bool  is_stack_sorted_lenient(t_stack stack, uint16_t stack_len)
{
  uint16_t i;

  i = 1;
  assert(stack.arr);
  while(i < stack_len)
  {
    if (stack.arr[i - 1] <= stack.arr[i])
      return (false);
    i++;
  }
  return (true);
}

// returns true only if all items are in stack a
bool  is_stack_sorted_strict(t_stack stack, uint16_t stack_len)
{
  uint16_t i;

  i = 1;
  assert(stack.arr);
  if (stack.split < stack_len)
    return (false);
  while(i < stack_len)
  {
    if (stack.arr[i - 1] <= stack.arr[i])
      return (false);
    i++;
  }
  return (true);
}

uint16_t  unnormalized_diff(t_stack stack, uint16_t stack_len)
{
  uint16_t i;
  uint16_t diff;

  i = 0;
  diff = 0;
  assert(stack.arr);
  while(i < stack_len)
  {
    diff += ft_abs(stack.arr[i] - (stack_len - i - 1));
    i++;
  }
  diff += stack_len - stack.split;
  return (diff);
} 

uint16_t  normalized_diff(t_stack stack, uint16_t stack_len)
{
  uint16_t i;
  uint16_t diff;

  i = 0;
  diff = 0;
  assert(stack.arr);
  while(i < stack_len)
  {
    if (ft_abs(stack.arr[i] - (stack_len - i - 1)))
      diff++;
    i++;
  }
  diff += stack_len - stack.split;
  return (diff);
} 

uint16_t  get_stack_diff(t_stack stack, uint16_t stack_len)
{
  return (unnormalized_diff(stack, stack_len));
  // TODO test other ways [ex normalized_diff()]
}
