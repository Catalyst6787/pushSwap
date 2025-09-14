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

# define STACK_LEN 10
# define MAX_DEPTH 7
# define SEED 696034213
# define DEBUG 0

typedef struct s_stack
{
  uint16_t *arr;
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

typedef struct s_data
{
  uint16_t max_depth;
  uint16_t stack_len;
  bool     best_set;
  uint16_t best_diff;
  long     visited_states;
  t_stack  *stack_arena;
  uint16_t *array_arena;
  t_stack  *best_stack;
  uint16_t *best_stack_arr;
  t_move   *best_moves;
  t_move   *current_moves;
} t_data;

// arr utils
void shuffle(uint16_t *array, size_t n, unsigned int seed);
void print_arr(const uint16_t *arr, const uint16_t size);
void print_stacks(const t_stack stack, uint16_t stack_len);
void init_sorted_stack(t_stack *stack, uint16_t stack_len);
bool  is_stack_sorted_lenient(t_stack stack, uint16_t stack_len);
bool  is_stack_sorted_strict(t_stack stack, uint16_t stack_len);
int  stack_cmp(t_stack ref, t_stack other, uint16_t stack_len);
uint16_t  unnormalized_diff(t_stack stack, uint16_t stack_len);
uint16_t  get_stack_diff(t_stack stack, uint16_t stack_len);

// tests
int  start_all_tests(bool verbose);

// arr ops
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

// logic
void recursion(t_data *data, t_move move, uint16_t depth);

// utils
unsigned int ft_abs(int val);
void  print_move(t_move move);

#endif

