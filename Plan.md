# recursion based ultimate push-swap

- for each node, recursively explore the descending nodes (depht first)
- use *arena allocation* to avoid mallocing every node

1.  on descent, store the actual stack for fast change
2.  on every node creating, check hashmap for existing node,
    1.  if node exists and depht > existing node depth -> drop node
    2.  if node exists and depth < existing node depth -> replace old depth with current
    3.  if node doesnt exist -> put hash in hashmap
3.  on ascent, free nodes so that we dont store the *whole* tree

## hash map

- to find the correct bucket, use idx = key % ht->capacity;
  - if it is already used (by a different key), go to the next slot to avoid conflicts

## arena

- in the arena, the nodes will be stored in depth first order, so that it is easily freed on ascentex:

``` sh
[n1]
 [n1.1]
  [n1.1.1]
  [n1.1.2]
 [n1.2]
[n2]
 [n2.1]
 [n2.2]
...
```

will become:

```
n1, n1.1, n1.1.1, n1.1.2, n1.2, n2, n2.1, n2.2 ...
```
