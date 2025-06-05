#include "./../src/AVLtree.h"
#include <assert.h>
#include <string.h>

int main(void) {
  int nums[] = {12, 56, 345, 46, 66, 99, 1, 4, 5, 6, 14, 47, 76};
  char *str[] = {"cat", "dog", "donkey", "turkey", "bull", "aggie", "chicken"};
  node *root = AVLtree();
  void *data;
  int x;
  node *str_root = AVLtree();
  void *str_data;
  for (x = 0; x < 13; ++x) {
    printf("\ninserting %d...\n", nums[x]);
    data = malloc(sizeof(int));
    *(int *)data = nums[x];
    insert(&root, data, compare_int);
    printf("insert complete...\n\n");
    print_tree(root, print_int, stdout);
  }
  data = malloc(sizeof(int));
  *(int *)data = 76;
  printf("inserting last node again\n");
  insert(&root, data, compare_int);
  print_tree(root, print_int, stdout);
  printf("\n\n\n\n");
  printf("_____________________________________________________________________"
         "_________\n");
  for (x = 0; x < 6; ++x) {
    printf("\ninserting %s...\n", str[x]);
    str_data = malloc(sizeof(char) * (strlen(str[x]) + 1));
    strcpy(str_data, str[x]);
    insert(&str_root, str_data, compare_string);
    printf("insert complete...\n\n");
    print_tree(str_root, print_string, stdout);
  }

  ///
  ///
  /// DELETING THE MAX STRING
  ///
  ///
  printf("delete_max;string\n");
  printf("_____________________________________________________________________"
         "_________\n\n");
  printf("\n");
  delete_max(str_root);
  print_tree(str_root, print_string, stdout);
  printf("\n\n");
  ///
  ///
  /// DELETING THE MIN STRING
  ///
  ///
  printf("delete_min;string\n");
  printf("_____________________________________________________________________"
         "_________\n\n");
  delete_min(str_root);
  print_tree(str_root, print_string, stdout);
  printf("\n\n");
  ///
  ///
  /// DELETING THE MAX INT
  ///
  ///
  printf("delete_max;int\n");
  printf("_____________________________________________________________________"
         "_________\n\n");
  printf("root: %p\tdata: %d\n", root, *(int *)root->data);
  print_int(root, stdout);
  printf("\n");

  root = delete_max(root);
  print_tree(root, print_int, stdout);
  printf("\n\n");
  ///
  ///
  /// DELETING THE MIN INT
  ///
  ///
  printf("delete_min;int\n");
  printf("_____________________________________________________________________"
         "_________\n\n");
  printf("root: %p\tdata: %d\n", root, *(int *)root->data);
  print_int(root, stdout);
  printf("\n");
  root = delete_min(root);
  print_tree(root, print_int, stdout);
  printf("\n\n");
  printf("remove 46;int\n");
  printf("_____________________________________________________________________"
         "_________\n\n");
  void *to_delete = malloc(sizeof(int));
  *(int *)to_delete = 46;
  avl_remove(&root, to_delete, compare_int);
  print_tree(root, print_int, stdout);
  return 0;
}
