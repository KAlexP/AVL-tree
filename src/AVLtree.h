#ifndef _AVL_TREE_
#define _AVL_TREE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOWED_IMBALANCE 1

// node definition
typedef struct node {
  void *data;
  struct node *left;
  struct node *right;
  int height;
} node;

// Function pointer definitions
typedef int (*CompareFunc)(const node *left, const node *right);
typedef void (*PrintFunc)(node *to_print, FILE *dest);

// Main Function prototypes
node *AVLtree(void);
void avl_free(node *root);
void avl_remove(node **root, const void *data, CompareFunc compare);
void insert(node **root, void *to_insert, CompareFunc compare);
node *make_node(const void *data);
node *find_min(node *root);
node *delete_min(node *root);
node *find_max(node *root);
node *delete_max(node *root);
void print_tree(node *root, PrintFunc print, FILE *dest);

// Helper function prototypes
node *rec_remove(node *curr, node *to_delete, CompareFunc compare);
node *rec_insert(node *new_node, node *curr, CompareFunc compare);
void rec_print(node *curr, PrintFunc print, FILE *dest, int spaces);
node *balance(node *curr);
node *one_right_rotation(node *to_rotate);
node *one_left_rotation(node *to_rotate);
node *two_right_rotation(node *to_rotate);
node *two_left_rotation(node *to_rotate);
int height(node *node);
node *rec_delete_min(node *curr);
node *rec_delete_max(node *curr);

// CompareFunc prototypes
int compare_int(const node *left, const node *right);
int compare_char(const node *left, const node *right);
int compare_float(const node *left, const node *right);
int compare_double(const node *left, const node *right);
int compare_string(const node *left, const node *right);

// PrintFunc prototypes
void print_int(node *to_print, FILE *dest);
void print_char(node *to_print, FILE *dest);
void print_float(node *to_print, FILE *dest);
void print_double(node *to_print, FILE *dest);
void print_string(node *to_print, FILE *dest);
void print_int2(node *to_print, FILE *dest);

#endif
