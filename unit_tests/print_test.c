#include "../src/AVLtree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  void *temp = malloc(sizeof(int));
  node *root = NULL;
  if (temp == NULL) {
    perror("malloc failed");
    return EXIT_FAILURE;
  }

  *(int *)temp = 12;
  root = make_node(temp);
  print_int(root, stdout);
  printf("\n");

  free(temp);
  temp = malloc(sizeof(double));
  *(double *)temp = 3.1415926535;
  root->data = temp;
  print_double(root, stdout);
  printf("\n");

  free(temp);
  temp = malloc(sizeof(char));
  *(char *)temp = 'A';
  root->data = temp;
  print_char(root, stdout);
  printf("\n");

  // don't forget to free your memory
  avl_free(root);	// note avl_free() frees the memory of node->data, and node. 
  return EXIT_SUCCESS;
}
