#include "ft_printf.h"
#include "push_swap.h"
#include "stdint.h"
#include <stdint.h>
#include <threads.h>
#include <assert.h>


void descend(t_data *data, uint16_t depth);
void	apply_move(t_data *data, uint16_t depth, t_move move);
int	is_move_possible(t_data *data, uint16_t depth, t_move move);

void recursion(t_data *data, t_move move, uint16_t depth)
{
	if (depth != 0)
	{
		ft_memcpy(&data->array_arena[depth * data->stack_len],
		          &data->array_arena[(depth - 1) * data->stack_len],
		          data->stack_len * sizeof(uint16_t));
		data->stack_arena[depth].split = data->stack_arena[depth - 1].split;
		if (!is_move_possible(data, depth, move))
			return ;
		apply_move(data, depth, move);
	}
	if (depth < data->max_depth)
		descend(data, depth + 1);
	else
	{
		ft_printf("leaf node:\ndepth: [%d],\nsplit: [%u],\nlast move: ", data->max_depth, data->stack_arena[depth].split);
		print_move(move);
		ft_printf("\n");
		print_stacks(data->stack_arena[depth], data->stack_len);
	}
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
		swap_a(&data->stack_arena[depth], data->stack_len);
	else if (move == sb)
		swap_b(&data->stack_arena[depth], data->stack_len);
	else if (move == ss)
		swap_s(&data->stack_arena[depth], data->stack_len);
	else if (move == pa)
		push_a(&data->stack_arena[depth], data->stack_len);
	else if (move == pb)
		push_b(&data->stack_arena[depth], data->stack_len);
	else if (move == ra)
		rotate_a(&data->stack_arena[depth], data->stack_len);
	else if (move == rb)
		rotate_b(&data->stack_arena[depth], data->stack_len);
	else if (move == rr)
		rotate_r(&data->stack_arena[depth], data->stack_len);
	else if (move == rra)
		rev_rotate_a(&data->stack_arena[depth], data->stack_len);
	else if (move == rrb)
		rev_rotate_b(&data->stack_arena[depth], data->stack_len);
	else if (move == rrr)
	 rev_rotate_r(&data->stack_arena[depth], data->stack_len);
	else
		assert(1 != 1);
}

int	is_move_possible(t_data *data, uint16_t depth, t_move move)
{
	if (move == sa && data->stack_arena[depth].split > 1)
		return (1);
	else if (move == sb && data->stack_len - data->stack_arena[depth].split > 1)
		return (1);
	if (move == ss && (data->stack_arena[depth].split > 1) && (data->stack_len - data->stack_arena[depth].split > 1))
		return (1);
	else if (move == pa && data->stack_len - data->stack_arena[depth].split > 0)
		return (1);
	if (move == pb && data->stack_arena[depth].split > 0)
		return (1);
	if (move == ra && data->stack_arena[depth].split > 1)
		return (1);
	else if (move == rb && data->stack_len - data->stack_arena[depth].split > 1)
		return (1);
	if (move == rr && (data->stack_arena[depth].split > 1) && (data->stack_len - data->stack_arena[depth].split > 1))
		return (1);
	if (move == rra && data->stack_arena[depth].split > 1)
		return (1);
	else if (move == rrb && data->stack_len - data->stack_arena[depth].split > 1)
		return (1);
	if (move == rrr && (data->stack_arena[depth].split > 1) && (data->stack_len - data->stack_arena[depth].split > 1))
		return (1);
	return (0);
}
