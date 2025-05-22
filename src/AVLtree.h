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
  typedef int (*CompareFunc)(const node *left, const node *right);
  typedef void (*PrintFunc)(node *to_print ,FILE *dest);

  // Main Function prototypes
  node* AVLtree(void);
  void avl_free(node *root);
  void avl_delete(const void *data);
  node*  insert(node *new_node,CompareFunc compare);
  node* make_node(void *data);
  node* find_min(node *root);
  void delete_min(void);
  node* find_max(node *root);
  void delete_max(void);
  void print_tree(node* root, PrintFunc print, FILE* dest);

	// Helper function prototypes
 	node* rec_insert(node *new_node,node *curr,CompareFunc compare);
	void rec_print(node *curr, PrintFunc print, FILE *dest,int spaces);
  node* balance(node *curr);
  node* one_right_rotation(node *to_rotate);
  node* one_left_rotation(node *to_rotate);
  node* two_right_rotation(node *to_rotate);
  node* two_left_rotation(node *to_rotate);
  // CompareFunc prototypes 
  
	// PrintFunc prototypes


#endif 
