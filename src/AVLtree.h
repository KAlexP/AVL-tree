#ifndef _AVL_TREE_
#define _AVL_TREE_

#include <stdio.h>
#include <stdlib.h>

	//	Node definition
	typedef struct node{
		void *data;
    node *left;
    node *right;
    int height;
  } node;

	// Function pointer definitions
  typedef int (*CompareFunc)(const void *left, const void *right);
  typedef void (*PrintFunc)(const char *message,FILE *destination);

  // Main Functions for interacting with AVLtree 
  node *AVLtree(void);
  void avl_free(node *root);
  void insert(node *new_node,CompareFunc compare);
  void remove(const void *data);
  void* find_min(void);
  void delete_min(void);
  void* find_max(void);
  void delete_max(void);
  int print_tree(node* root, PrintFunc print);

  // Helper function prototypes

	// CompareFunc prototypes 
  
  // PrintFunc prototypes


#endif 
