#include "../libft/includes/libft.h"
#include "push_swap.h"
#include "../libft/includes/ft_printf.h"
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
  t_arr base;

  base.size = STACK_LEN;
  base.diff = 0;
  base.arr = malloc(sizeof(uint16_t) * base.size);
  init_sorted_arr(base);
  ft_printf("generating random stack of length=%d\n", STACK_LEN);
  // print_arr(base.arr, base.size);
  ft_printf("sorted list:\n");
  print_arr(base.arr, base.size);
  shuffle(base.arr, STACK_LEN);
  ft_printf("\nunsorted list:\n");
  print_arr(base.arr, base.size);
  ft_printf("\n\nLaunching pushSwap:\n");
  free(base.arr);
  base.arr = NULL;
}
