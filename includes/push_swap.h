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

typedef struct s_stack
{
  uint16_t *arr;
  uint16_t diff;
  uint16_t split;
} t_stack;

void shuffle(uint16_t *array, size_t n, unsigned int seed);
void print_arr(const uint16_t *arr, const uint16_t size);
void print_stacks(const t_stack stack, uint16_t stack_len);
void init_sorted_stack(t_stack *stack, uint16_t stack_len);
int  stack_cmp(t_stack ref, t_stack other, uint16_t stack_len);
int start_all_tests(void);
int	swap_a(t_stack stack, uint16_t stack_len);
int swap_b(t_stack stack, uint16_t stack_len);
int	push_b(t_stack *stack, uint16_t stack_len);
int push_a(t_stack *stack, uint16_t stack_len);

#endif

