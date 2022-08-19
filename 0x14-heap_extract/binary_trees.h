#ifndef BINARY_TREES_H_
#define BINARY_TREES_H_

/* ==== LIBRARIES ==== */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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

typedef struct binary_tree_s binary_tree_t;

/* ==== Max Binary Heap ==== */
typedef struct binary_tree_s heap_t;

/* ==== PROTOTYPES ==== */
void binary_tree_print(const binary_tree_t *);
int heap_extract(heap_t **root);

#endif /* BINARY_TREES_H_ */
