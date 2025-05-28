#include "./../src/AVLtree.h"
#include <assert.h>

int main(void) {
  int nums[] = {12, 56, 345, 46, 66, 99, 1, 4, 5, 6, 14, 47, 76};
  node *root = AVLtree();
  void *data = malloc(sizeof(int));
  node *temp;
  /*

  *(int *)data = 22;
  printf("printing NULL tree\n");
  print_tree(root, print_int, stdout);
  temp = make_node(data);
  printf("\ninserting 22...\n\n");
  insert(&root, temp, compare_int);
  print_tree(root, print_int, stdout);

  printf("\ninserting 36...\n\n");
  data = malloc(sizeof(int));
  *(int *)data = 36;
  temp = make_node(data);
  insert(&root, temp, compare_int);
  print_tree(root, print_int, stdout);
*/
  for (int x = 0; x < 13; ++x) {
    printf("inserting %d...\n\n", nums[x]);
    data = malloc(sizeof(int));
    *(int *)data = nums[x];
    temp = make_node(data);
    insert(&root, temp, compare_int);
    print_tree(root, print_int, stdout);
  }
  data = malloc(sizeof(int));
  *(int *)data = 76;
  temp = make_node(data);
  assert(temp != root);
  printf("inserting last node again\n");
  insert(&root, temp, compare_int);
  print_tree(root, print_int2, stdout);
  return 0;
}
