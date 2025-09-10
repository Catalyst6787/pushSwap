#include "push_swap.h"
#include <stdlib.h>

void shuffle(uint16_t *array, size_t n, unsigned int seed)
{
    if (seed == 0)
        seed = SEED;
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand_r(&seed) / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}


