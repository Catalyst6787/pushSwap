#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line_bonus.h"
# include "../libft/includes/ft_printf.h"
#include  "sys/types.h"
#include  <stdint.h>

# define STACK_LEN 5
# define MAX_DEPTH 1
# define SEED 696034213

typedef struct s_arr
{
  uint16_t *arr;
  uint16_t size;
  uint16_t diff;
} t_arr;

void shuffle(uint16_t *array, size_t n);
void print_arr(uint16_t *arr, uint16_t size);
void init_sorted_arr(t_arr arr);


#endif

