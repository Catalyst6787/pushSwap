#include "../libft/includes/libft.h"
#include "push_swap.h"
#include "../libft/includes/ft_printf.h"
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
  t_stack base;

  base.split = STACK_LEN;
  base.diff = 0;
  base.arr = malloc(sizeof(uint16_t) * STACK_LEN);
  init_sorted_stack(base);
  ft_printf("generating random stack of length=%d\n", STACK_LEN);
  ft_printf("sorted list:\n");
  print_arr(base.arr, STACK_LEN);
  print_stacks(base);
  shuffle(base.arr, STACK_LEN, SEED);
  ft_printf("unsorted list:\n");
  print_arr(base.arr, STACK_LEN);
  print_stacks(base);
  ft_printf("\nLaunching pushSwap:\n");
  free(base.arr);
  base.arr = NULL;
}
