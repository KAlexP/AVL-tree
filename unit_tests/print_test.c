#include "../src/AVLtree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  void *temp = malloc(sizeof(int));
  node *root = malloc(sizeof(node));
  if (temp == NULL) {
    perror("malloc failed");
    return EXIT_FAILURE;
  }

  *(int *)temp = 12;

  root = make_node(temp);
  print_int(root, stdout);
  return EXIT_SUCCESS;
}
