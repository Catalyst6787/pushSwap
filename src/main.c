#include "../libft/includes/libft.h"
#include "push_swap.h"
#include "../libft/includes/ft_printf.h"
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
  t_stack base;
  uint16_t stack_len;

  if (!start_all_tests())
    return(ft_printf("test_failed..."), 1);
  stack_len = STACK_LEN;
  base.split = STACK_LEN;
  base.diff = 0;
  base.arr = malloc(sizeof(uint16_t) * stack_len);
  init_sorted_stack(&base, stack_len);
  // ft_printf("sorted list:\n");
  // print_stacks(base, stack_len);
  shuffle(base.arr, stack_len, SEED);
  // ft_printf("\nLaunching pushSwap:\n");
  free(base.arr);
  base.arr = NULL;
}
