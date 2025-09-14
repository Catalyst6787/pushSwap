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
  if (!start_all_tests(false))
    return(ft_printf("test_failed..."), 1);
  init_sorted_stack(&data.stack_arena[0], data.stack_len);
  shuffle(data.stack_arena[0].arr, data.stack_len, SEED);
  ft_printf("starting point:\n");
  print_stacks(data.stack_arena[0], data.stack_len);
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

  step = 0;
  total_states = 0;
  first = true;
  while (first || data->best_diff > 0)
  {
    recursion(data, -1, 0);
    ft_printf("Step n°[%d]:\nexplored [%u] states.\nBest state:\nDiff [%d]\n",
              step,
              data->visited_states,
              data->best_diff);
    print_stacks(*data->best_stack, data->stack_len);
    ft_memcpy(&data->stack_arena[0], data->best_stack, sizeof(t_stack));
    ft_memcpy(&data->array_arena[0], data->best_stack_arr, sizeof(uint16_t) * data->stack_len);
    step++;
    total_states += data->visited_states;
    data->visited_states = 0;
    data->best_set = false;
    first = false;
  }
  ft_printf("finished sorting in [%d] steps, total operations: [%d]\n", step, step * data->stack_len);
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
  data->stack_arena = malloc(sizeof(t_stack) * (data->max_depth + 1));
  if (!data->stack_arena)
    return (free_data(data), 1);
  data->array_arena = malloc(sizeof(uint16_t) * stack_len * (max_depth + 1));
  if (!data->array_arena)
    return (free_data(data), 1);
  for (int i = 0; i < (max_depth + 1); i++)
    data->stack_arena[i].arr = &data->array_arena[i * stack_len];
  data->best_stack = malloc(sizeof(t_stack));
  if (!data->best_stack)
    return (free_data(data), 1);
  data->best_stack_arr = malloc(sizeof(uint16_t) * data->stack_len);
  if (!data->best_stack_arr)
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
  if (data->stack_arena)
    free(data->stack_arena);
  if (data->array_arena)
    free(data->array_arena);
  if (data->best_stack)
    free(data->best_stack);
  if (data->best_stack_arr)
    free(data->best_stack_arr);
  if (data->best_moves)
    free(data->best_moves);
  if (data->current_moves)
    free(data->current_moves);
}
