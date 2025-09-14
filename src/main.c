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
  init_sorted_stack(&data.stack_arena[0], data.stack_len);
  print_stacks(data.stack_arena[0], data.stack_len);
  // shuffle(data.stack_arena[0].arr, data.stack_len, SEED);
  ft_printf("Launching Recursion:\n");
  recursion(&data, -1, 0);
  ft_printf("Recursion done\n");
  ft_printf("freeing data\n");
  free_data(&data);
  ft_printf("data successfuly freed\n");
}

int init_data(t_data *data, int max_depth, int stack_len)
{
  data->max_depth = max_depth;
  data->stack_len = stack_len;
  data->stack_arena = malloc(sizeof(t_stack) * (data->max_depth + 1));
  if (!data->stack_arena)
    return (free_data(data), 1);
  data->array_arena = malloc(sizeof(uint16_t) * stack_len * (max_depth + 1));
  if (!data->array_arena)
    return (free_data(data), 1);
  for (int i = 0; i < (max_depth + 1); i++)
    data->stack_arena[i].arr = &data->array_arena[i * stack_len];
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
  if (data->best_moves)
    free(data->best_moves);
  if (data->current_moves)
    free(data->current_moves);
  ft_memset(data, 0, sizeof(t_data));
}
