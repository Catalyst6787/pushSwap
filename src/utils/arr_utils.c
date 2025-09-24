#include "colors.h"
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

void print_stacks(const uint16_t *stack, uint16_t stack_len)
{
  int i;
  const uint16_t *split;

  split = stack;
  stack++;
  i = *split -1;
  ft_printf("stack_a:\n");
  while (i >= 0)
  {
    ft_printf("|%u", stack[i]);
    i--;
  }
  if (i != *split -1)
    ft_printf("|");
  i = *split;
  ft_printf("\nstack_b:\n");
  while (i < stack_len)
  {
    ft_printf("|%u", stack[i]);
    i++;
  }
  if (i != *split)
    ft_printf("|");
  ft_printf("\n");
}

void init_sorted_stack(uint16_t *stack, uint16_t stack_len)
{
  int i;
  uint16_t *split;

  i = stack_len;
  split = stack;
  stack++;
  while (i > 0)
  {
    stack[stack_len - i] = i - 1;
    i--;
  }
  *split = stack_len;
}

int stack_cmp(uint16_t *ref, uint16_t *other, uint16_t stack_len)
{
  uint16_t i;
  uint16_t *ref_split;
  uint16_t *other_split;

  i = 0;
  ref_split = ref;
  ref++;
  other_split = other;
  other++;
  if (*ref_split != *other_split)
    return (1);
  while (i < stack_len)
  {
    if (ref[i] != other[i])
      return (1);
    i++;
  }
  return (0);
}

// returns true even if items in stack b
bool  is_stack_sorted_lenient(uint16_t *stack, uint16_t stack_len)
{
  uint16_t i;

  i = 1;
  stack++;
  assert(stack);
  while(i < stack_len)
  {
    if (stack[i - 1] <= stack[i])
      return (false);
    i++;
  }
  return (true);
}

// returns true only if all items are in stack a
bool  is_stack_sorted_strict(uint16_t *stack, uint16_t stack_len)
{
  uint16_t i;

  i = 1;
  assert(stack);
  if (stack[0] < stack_len)
    return (false);
  stack++;
  while(i < stack_len)
  {
    if (stack[i - 1] <= stack[i])
      return (false);
    i++;
  }
  return (true);
}

uint16_t  unnormalized_diff(uint16_t *stack, uint16_t stack_len)
{
  uint16_t i;
  uint16_t diff;
  uint16_t *split;

  i = 0;
  diff = 0;
  split = stack;
  stack++;
  assert(stack);
  while(i < stack_len)
  {
    diff += ft_abs(stack[i] - (stack_len - i - 1));
    i++;
  }
  diff += stack_len - *split;
  return (diff);
} 

uint16_t  normalized_diff(uint16_t *stack, uint16_t stack_len)
{
  uint16_t i;
  uint16_t diff;
  uint16_t *split;

  i = 0;
  diff = 0;
  split = stack;
  stack++;
  assert(stack);
  while(i < stack_len)
  {
    if (ft_abs(stack[i] - (stack_len - i - 1)))
      diff++;
    i++;
  }
  diff += stack_len - *split;
  return (diff);
} 

uint16_t  get_stack_diff(uint16_t *stack, uint16_t stack_len)
{
  // return (unnormalized_diff(stack, stack_len));
  return (unnormalized_diff(stack, stack_len));
  // TODO test other ways [ex normalized_diff()]
}
