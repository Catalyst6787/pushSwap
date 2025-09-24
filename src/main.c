#include "colors.h"
#include "push_swap.h"

#include <stdint.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"
#include "errors.h"


int  init_data(t_data *data, int max_depth, int stack_len);
void free_data(t_data *data);

int main(void)
{
  t_data data;

  ft_printf("initalizing data...\n");
  if (init_data(&data, MAX_DEPTH, STACK_LEN))
    return (ft_printf("Malloc error when initialising data :(\n"), 1);
  ft_printf("data initialized\n");
  if (!start_all_tests(false))
    return(ft_printf("test_failed..."), 1);
  init_sorted_stack(data.array_arena, data.stack_len);
  shuffle(data.array_arena, data.stack_len, SEED);
  ft_printf("starting point:\n");
  print_stacks(data.array_arena, data.stack_len);
  ft_printf("Launching Recursion:\n");
  repeat_till_sorted(&data);
  ft_printf("Recursion done\n");
  ft_printf("HashMap stats:\n");
  printf("unique elements: [%lu]\nhits: [%lu]\ncollisions: [%lu]\nfilled: [%f/1]\n", data.hashmap.unique_elements, data.hashmap.hits, data.hashmap.collisions, (float)data.hashmap.unique_elements / (float)data.hashmap.capacity);
  printf("collision rate: [%f]\n", (float)data.hashmap.collisions / (float)data.hashmap.unique_elements);
  printf("visited states: [%lu]\n", data.visited_states);
  printf("skipped states: [%lu]\n", data.hashmap.skipped);
  printf("replaced states: [%lu]\n", data.hashmap.replaces);
  ft_printf("freeing data\nExiting\n");
  free_data(&data);
}

int init_data(t_data *data, int max_depth, int stack_len)
{
  ft_memset(data, 0, sizeof(t_data));
  ft_memset(&data->hashmap, 0, sizeof(t_hashmap));
  data->max_depth = max_depth;
  data->stack_len = stack_len;
  data->best_set = false;
  data->best_diff = 0;
  data->visited_states = 0;
  data->array_arena = malloc(sizeof(uint16_t) * (stack_len + 1) * (max_depth + 1));
  if (!data->array_arena)
    return (free_data(data), 1);
  data->best_arr = malloc(sizeof(uint16_t) * (stack_len + 1));
  if (!data->best_arr)
    return (free_data(data), 1);
  data->best_moves = malloc(sizeof(t_move) * data->max_depth);
  if (!data->best_moves)
    return (free_data(data), 1);
  data->current_moves = malloc(sizeof(t_move) * data->max_depth);
  if (!data->current_moves)
    return (free_data(data), 1);
  data->hashmap.capacity = ARBITRARY_HASHMAP_MODIFIER;
  for (int i = 0; i < data->max_depth; i++)
    data->hashmap.capacity *= 8;
  data->hashmap.entries = malloc(sizeof(t_entry) * data->hashmap.capacity);
  if (!data->hashmap.entries)
    return (free_data(data), 1);
  ft_memset(data->hashmap.entries, 0, sizeof(t_entry) * data->hashmap.capacity);
  return (0);
}

void free_data(t_data *data)
{
  if (!data)
    return ;
  if (data->array_arena)
    free(data->array_arena);
  if (data->best_arr)
    free(data->best_arr);
  if (data->best_moves)
    free(data->best_moves);
  if (data->current_moves)
    free(data->current_moves);
  if (data->hashmap.entries)
    free(data->hashmap.entries);
}
