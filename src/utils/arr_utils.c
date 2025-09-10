#include "push_swap.h"
#include <stdint.h>

void print_arr(uint16_t *arr, uint16_t size)
{
  uint16_t i;

  i = 0;
  printf("array: ");
  while (i < size)
    printf("%u", arr[i++]);
  printf("\n");
}

void init_sorted_arr(t_arr arr)
{
  uint16_t i;

  i = 0;
  while (i < arr.size)
  {
    arr.arr[i] = i;
    i++;
  }
}
