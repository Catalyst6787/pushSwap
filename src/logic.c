#include "ft_printf.h"
#include "push_swap.h"
#include "stdint.h"
#include <stdint.h>
#include <threads.h>
#include <assert.h>

void recursion(t_data *data, t_move move, uint16_t depth);
void descend(t_data *data, uint16_t depth);
void	apply_move(t_data *data, uint16_t depth, t_move move);
int	is_move_possible(t_data *data, uint16_t depth, t_move move);
void  repeat_till_sorted(t_data *data);

void recursion(t_data *data, t_move move, uint16_t depth)
{
	uint16_t diff;
	uint64_t key;
	int			 existing_depth;

	// (void)existing_depth;
	if (depth != 0)
	{
		ft_memcpy(&data->array_arena[depth * (data->stack_len + 1)],
		          &data->array_arena[(depth - 1) * (data->stack_len + 1)],
		          (data->stack_len + 1) * sizeof(uint16_t));
		if (!is_move_possible(data, depth, move))
			return ;
		apply_move(data, depth, move);
		key = get_fnv_1a_hash(&data->array_arena[depth * (data->stack_len + 1)], depth);
		existing_depth = hashmap_get(data, key);
		if (existing_depth >= 0 && (uint16_t)existing_depth <= depth)
		{
			data->hashmap.skipped++;
			return ;
		}
		hashmap_put(data, key, depth);
		data->visited_states++;
		diff = get_stack_diff(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
		data->current_moves[depth - 1] = move;
	}
	if (depth != 0
	    && (!data->best_set || diff < data->best_diff
	    || (diff == data->best_diff && depth < data->best_depth)))
	{
		data->best_diff = diff;
		data->best_depth = depth;
		ft_memcpy(data->best_moves, data->current_moves, sizeof(t_move) * depth);
		ft_memcpy(data->best_arr, &data->array_arena[depth * (data->stack_len + 1)], sizeof(uint16_t) * (data->stack_len + 1));
		data->best_set = true;
	}
	if (depth < data->max_depth)
		descend(data, depth + 1);
}

void  repeat_till_sorted(t_data *data)
{
  bool first;
  unsigned int step;
  uint64_t total_states;
  unsigned int total_ops;

  step = 0;
  total_states = 0;
  first = true;
  total_ops = 0;
  data->best_diff = get_stack_diff(&data->array_arena[0], data->stack_len);
  data->best_set = false;
  while (first || data->best_diff > 0)
  {
  	if (step == 1)
  	{
  		step += 0;
  	}
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
  data->visited_states = total_states;
  ft_printf("finished sorting in [%d] steps, total operations: [%d]\n", step, total_ops);
  ft_printf("total explored states: [%d]\n", total_states);
}

void	descend(t_data *data, uint16_t depth)
{
	t_move move;

	move = sa;
	while (move <= rrr)
	{
		recursion(data, move, depth);
		move++;
	}
}

void	apply_move(t_data *data, uint16_t depth, t_move move)
{
	if (move == sa)
		swap_a(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == sb)
		swap_b(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == ss)
		swap_s(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == pa)
		push_a(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == pb)
		push_b(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == ra)
		rotate_a(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == rb)
		rotate_b(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == rr)
		rotate_r(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == rra)
		rev_rotate_a(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == rrb)
		rev_rotate_b(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else if (move == rrr)
	 rev_rotate_r(&data->array_arena[depth * (data->stack_len + 1)], data->stack_len);
	else
		assert(1 != 1);
}

int	is_move_possible(t_data *data, uint16_t depth, t_move move)
{
	if (move == sa && data->array_arena[depth * (data->stack_len + 1)] > 1)
		return (1);
	else if (move == sb && data->stack_len - data->array_arena[depth * (data->stack_len + 1)] > 1)
		return (1);
	if (move == ss && (data->array_arena[depth * (data->stack_len + 1)] > 1) && (data->stack_len - data->array_arena[depth * (data->stack_len + 1)] > 1))
		return (1);
	else if (move == pa && data->stack_len - data->array_arena[depth * (data->stack_len + 1)] > 0)
		return (1);
	if (move == pb && data->array_arena[depth * (data->stack_len + 1)] > 0)
		return (1);
	if (move == ra && data->array_arena[depth * (data->stack_len + 1)] > 1)
		return (1);
	else if (move == rb && data->stack_len - data->array_arena[depth * (data->stack_len + 1)] > 1)
		return (1);
	if (move == rr && (data->array_arena[depth * (data->stack_len + 1)] > 1) && (data->stack_len - data->array_arena[depth * (data->stack_len + 1)] > 1))
		return (1);
	if (move == rra && data->array_arena[depth * (data->stack_len + 1)] > 1)
		return (1);
	else if (move == rrb && data->stack_len - data->array_arena[depth * (data->stack_len + 1)] > 1)
		return (1);
	if (move == rrr && (data->array_arena[depth * (data->stack_len + 1)] > 1) && (data->stack_len - data->array_arena[depth * (data->stack_len + 1)] > 1))
		return (1);
	return (0);
}
