#include "colors.h"
#include "push_swap.h"

#include <stdint.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"
#include "errors.h"


int  init_data(t_data *data, int max_depth, int stack_len);
void repeat_till_sorted(t_data *data);
void free_data(t_data *data);

int main(void)
{
  t_data data;

  ft_printf("initalizing data...\n");
  if (init_data(&data, MAX_DEPTH, STACK_LEN))
    return (ft_printf("Malloc error when initialising data :(\n"), 1);
  ft_printf("data initialized\n");
  if (!start_all_tests(true))
    return(ft_printf("test_failed..."), 1);
  init_sorted_stack(data.array_arena, data.stack_len);
  shuffle(data.array_arena, data.stack_len, SEED);
  ft_printf("starting point:\n");
  print_stacks(data.array_arena, data.stack_len);
  ft_printf("Launching Recursion:\n");
  repeat_till_sorted(&data);
  ft_printf("Recursion done\n");
  ft_printf("freeing data\nExiting\n");
  free_data(&data);
}

void  repeat_till_sorted(t_data *data)
{
  bool first;
  unsigned int step;
  long long total_states;
  unsigned int total_ops;

  step = 0;
  total_states = 0;
  first = true;
  total_ops = 0;
  data->best_diff = get_stack_diff(&data->array_arena[0], data->stack_len);
  data->best_set = false;
  while (first || data->best_diff > 0)
  {
    recursion(data, -1, 0);
    if (!data->best_set)
    {
      ft_printf("no better move found. exiting...\n");
      return ;
    }
    if (DEBUG)
    {
      ft_printf("Step n°[%d]:\nexplored [%u] states.\nBest state:\nDiff [%d]\n",
              step,
              data->visited_states,
              data->best_diff);
      print_stacks(data->best_arr, data->stack_len);
    }
    for (int i = 0; i < data->best_depth; i++)
    {
      print_move(data->best_moves[i]);
      ft_printf("\n");
    }
    ft_memcpy(&data->array_arena[0], data->best_arr, sizeof(uint16_t) * (data->stack_len + 1));
    data->best_diff = get_stack_diff(&data->array_arena[0], data->stack_len);
    step++;
    total_states += data->visited_states;
    total_ops += data->best_depth;
    data->visited_states = 0;
    data->best_set = false;
    first = false;
  }
  ft_printf("finished sorting in [%d] steps, total operations: [%d]\n", step, total_ops);
  ft_printf("total explored states: [%d]\n", total_states);
}

int init_data(t_data *data, int max_depth, int stack_len)
{
  ft_memset(data, 0, sizeof(t_data));
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
}
