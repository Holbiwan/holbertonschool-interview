# holbertonschool-interview 📌
<h1 align="center">Heap Insert</h1>

![Heap Insert](https://zupimages.net/up/24/21/0lhe.png)

## Requirements

- gcc 4.8.4
- Ubuntu 14.04 LTS

## Compilation

```sh
gcc -Wall -Werror -Wextra -pedantic
```

## Basic Binary Tree

```sh
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
```

## Max Binary Heap

```sh
typedef struct binary_tree_s heap_t;
```

## Author

**Sabrina PAPEAU**  
Find me on [Github](https://github.com/Holbiwan)

