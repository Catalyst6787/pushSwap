#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdint.h>
# include <stdbool.h>

# include "libft.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include  "sys/types.h"
# include "colors.h"
# include "error.h"

# define STACK_LEN 10
# define MAX_DEPTH 6
# define SEED 696035213
# define DEBUG 1
# define ARBITRARY_HASHMAP_MODIFIER 1
# define FNV_1A_OFFSET_BASIS 1469598103934665603ULL
# define FNV_1A_PRIME 1099511628211ULL

// TODO check if uint_fast16_t is faster than uint16_t

typedef enum e_move
{
  na = 0,
  sa,
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

typedef struct s_entry {
  uint64_t key;
  bool     set;
  uint16_t depth;
} t_entry;

typedef struct s_hashmap {
  t_entry  *entries;
  uint64_t capacity;
  uint64_t collisions;
  uint64_t hits;
  uint64_t skipped;
  uint64_t replaces;
  uint64_t unique_elements;
} t_hashmap;

typedef struct s_data
{
  uint16_t  max_depth;
  uint16_t  stack_len;
  bool      best_set;
  uint16_t  best_diff;
  uint16_t  best_depth;
  uint64_t  visited_states;
  uint16_t  *array_arena;
  uint16_t  *best_arr;
  t_move    *best_moves;
  t_move    *current_moves;
  t_hashmap hashmap;
} t_data;

// arr utils
void shuffle(uint16_t *array, size_t n, unsigned int seed);
void print_arr(const uint16_t *arr, const uint16_t size);
void print_stacks(const uint16_t *stack, uint16_t stack_len);
void init_sorted_stack(uint16_t *stack, uint16_t stack_len);
bool  is_stack_sorted_lenient(uint16_t *stack, uint16_t stack_len);
bool  is_stack_sorted_strict(uint16_t *stack, uint16_t stack_len);
int  stack_cmp(uint16_t *ref, uint16_t *other, uint16_t stack_len);
uint16_t  unnormalized_diff(uint16_t *stack, uint16_t stack_len);
uint16_t  get_stack_diff(uint16_t *stack, uint16_t stack_len);

// tests
int  start_all_tests(bool verbose);

// arr ops
int	 swap_a(uint16_t *stack, uint16_t stack_len);
int  swap_b(uint16_t *stack, uint16_t stack_len);
int  swap_s(uint16_t *stack, uint16_t stack_len);
int	 push_b(uint16_t *stack, uint16_t stack_len);
int  push_a(uint16_t *stack, uint16_t stack_len);
int  rotate_a(uint16_t *stack, uint16_t stack_len);
int  rotate_b(uint16_t *stack, uint16_t stack_len);
int  rotate_r(uint16_t *stack, uint16_t stack_len);
int  rev_rotate_a(uint16_t *stack, uint16_t stack_len);
int  rev_rotate_b(uint16_t *stack, uint16_t stack_len);
int  rev_rotate_r(uint16_t *stack, uint16_t stack_len);

// logic
void  recursion(t_data *data, t_move move, uint16_t depth);
void  repeat_till_sorted(t_data *data);

// utils
unsigned int ft_abs(int val);
void  print_move(t_move move);

// hashmap
uint64_t	get_fnv_1a_hash(uint16_t *stack, int n);
int 			hashmap_get(t_data *data, uint64_t key);
void			hashmap_put(t_data *data, uint64_t key, uint16_t depth);

#endif

