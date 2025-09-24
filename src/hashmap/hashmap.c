#include "ft_printf.h"
#include "push_swap.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>

uint64_t	get_fnv_1a_hash(uint16_t *stack, int n);
int 			hashmap_get(t_data *data, uint64_t key);
void			hashmap_put(t_data *data, uint64_t key, uint16_t depth);

uint64_t get_fnv_1a_hash(uint16_t *stack, int n)
{
    uint64_t h = FNV_1A_OFFSET_BASIS;
    for (int i = 0; i < n; i++) {
        h ^= stack[i];
        h *= FNV_1A_PRIME;
    }
    return h;
}

int hashmap_get(t_data *data, uint64_t key)
{
    uint64_t idx;

    idx = key % data->hashmap.capacity;
    while (data->hashmap.entries[idx].set)
    {
        if (data->hashmap.entries[idx].key == key)
            return (data->hashmap.hits++, data->hashmap.entries[idx].depth);
        idx = (idx + 1) % data->hashmap.capacity;
    }
    return (-1);
}

void	hashmap_put(t_data *data, uint64_t key, uint16_t depth)
{
	uint64_t idx;
	uint64_t probes;

	idx = key % data->hashmap.capacity;
	probes = 0;
	while (data->hashmap.entries[idx].set && probes++ < data->hashmap.capacity)
	{
		if (data->hashmap.entries[idx].key == key)
		{
			if (data->hashmap.entries[idx].depth > depth)
			{
				data->hashmap.entries[idx].depth = depth;
				data->hashmap.replaces++;
				return ;
			}
			else
				return ;
		}
		else
		{
			data->hashmap.collisions++;
			idx = (idx + 1) % data->hashmap.capacity;
		}
	}
	if (probes == data->hashmap.capacity)
	{
		ft_printf("hashmap full\n");
		assert(1 != 1);
		return ;
	}
	data->hashmap.entries[idx].key = key;
	data->hashmap.entries[idx].depth = depth;
	data->hashmap.entries[idx].set = true;
	data->hashmap.unique_elements++;
}

