#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include  <stdint.h>
# include <stdbool.h>

# include "libft.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include  "sys/types.h"
# include "colors.h"
# include "error.h"

# define STACK_LEN 5
# define MAX_DEPTH 1
# define SEED 696034213

typedef struct s_stack
{
  uint16_t *arr;
  uint16_t diff;
  uint16_t split;
} t_stack;

typedef enum e_move
{
  sa = 0,
  sb,
  ss,
  pa,
  pb,
  ra,
  rb,
  rr,
  rra,
  rrb,
  rrr
} t_move;

void shuffle(uint16_t *array, size_t n, unsigned int seed);
void print_arr(const uint16_t *arr, const uint16_t size);
void print_stacks(const t_stack stack, uint16_t stack_len);
void init_sorted_stack(t_stack *stack, uint16_t stack_len);
bool  is_stack_sorted(t_stack stack, uint16_t stack_len);
int  stack_cmp(t_stack ref, t_stack other, uint16_t stack_len);
int  start_all_tests(void);
int	 swap_a(t_stack *stack, uint16_t stack_len);
int  swap_b(t_stack *stack, uint16_t stack_len);
int  swap_s(t_stack *stack, uint16_t stack_len);
int	 push_b(t_stack *stack, uint16_t stack_len);
int  push_a(t_stack *stack, uint16_t stack_len);
int  rotate_a(t_stack *stack, uint16_t stack_len);
int  rotate_b(t_stack *stack, uint16_t stack_len);
int  rotate_r(t_stack *stack, uint16_t stack_len);
int  rev_rotate_a(t_stack *stack, uint16_t stack_len);
int  rev_rotate_b(t_stack *stack, uint16_t stack_len);
int  rev_rotate_r(t_stack *stack, uint16_t stack_len);

#endif

