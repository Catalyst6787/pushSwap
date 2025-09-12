#include "ft_printf.h"
#include "push_swap.h"

unsigned int ft_abs(int val)
{
  if (val < 0)
    return (-val);
  return (val);
}

void  print_move(t_move move)
{
  if (move == sa)
    ft_printf("sa");
  else if (move == sb)
    ft_printf("sb");
  else if (move == ss)
    ft_printf("ss");
  else if (move == pa)
    ft_printf("pa");
  else if (move == pb)
    ft_printf("pb");
  else if (move == ra)
    ft_printf("ra");
  else if (move == rb)
    ft_printf("rb");
  else if (move == rr)
    ft_printf("rr");
  else if (move == rra)
    ft_printf("rra");
  else if (move == rrb)
    ft_printf("rrb");
  else if (move == rrr)
    ft_printf("rrr");
  else if ((int)move == -1)
    ft_printf("root");
  else
    ft_printf("Error, move not found!");
}
