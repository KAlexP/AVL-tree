#ifndef _AVL_TREE_
#define _AVL_TREE_

#include <stdio.h>
#include <stdlib.h>

#define ALLOWED_IMBALANCE 1

	// node definition
	typedef struct node{
		void *data;
		struct node *left;
		struct node *right;
		int height;
  } node;

	// Function pointer definitions
  typedef int (*CompareFunc)(const void *left, const void *right);
  typedef void (*PrintFunc)(node *to_print ,FILE *dest);

  // Main Function prototypes
  node* AVLtree(void);
  void avl_free(node *root);
  void avl_delete(const void *data);
  void insert(node *new_node,CompareFunc compare);
  node* make_node(void *data);
  node* find_min(node *root);
  void delete_min(void);
  node* find_max(node *root);
  void delete_max(void);
  void print_tree(node* root, PrintFunc print, FILE* dest);

	// Helper function prototypes
	void rec_print(node *curr, PrintFunc print, FILE *dest,int spaces);
  node* balance(node *curr);
  // CompareFunc prototypes 
  
	// PrintFunc prototypes


#endif 
