#include "AVLtree.h"

///////////////////////////////////////////////////////////////////////////////
///
///
///		Below are the Main function prototypes
///
///////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
 * Function Title: AVLtree
 * Summary: returns a NULL pointer. Basically makes using the tree more readable
 *
 * Inputs: n/a
 * Outputs: NULL pointer
 *******************************************************************************/
node *AVLtree(void) { return NULL; }

/*******************************************************************************
 * Function Title: avl_free
 * Summary: This function frees the memory of the tree, effectively deleting
 *  				 the tree.
 *
 * Inputs:
 * 	node *root: The starting point of what we need deleted.
 * Outputs: n/a
 ********************************************************************************
 * Pseudocode
 *		Begin
 *			set up temp variable
 *			if there is a left child
 *				recursively call delete on left
 *			if there is a right child
 *				recursively call delete on right
 *			if node memory isn't NULL
 *				if data memory isn't NULL
 *					free the data memory
 *				free the node memory
 *				set pointers to NULL to prevent bad access
 *   End
 *******************************************************************************/
void avl_free(node *root) { //	Begin
  if (root == NULL) {
    return;
  }
  node *temp = root;        //		set up temp variable
  if (temp->left != NULL) { //		if there is a left child
    avl_free(temp->left);   //			recursively call delete on left
  }
  if (temp->right != NULL) { //		if there is a right child
    avl_free(temp->right);   //			recursively call delete on right
  }
  if (temp != NULL) {
    if (temp->data != NULL)
      free(temp->data); //		free the data memory
    free(temp);         //		free the node memory
    temp = NULL;
  }
  return;
} //	End

/*******************************************************************************
 * Function Title: remove
 * Summary: This function looks for certain value, and if it's found then is
 * 				 is removed from the tree.
 *
 * Inputs:
 * 	const void *data: data to be deleted
 * Outputs: n/a
 ********************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 *******************************************************************************/
void avl_remove(node **root, void *data, CompareFunc compare) {
  if (*root == NULL) {
    printf("Error: empty tree-avl_remove\n");
  } else {
    node *to_search = make_node(data);
    *root = rec_remove(*root, to_search, compare);
  }
}

/*******************************************************************************
 * Function Title: insert
 * Summary: easier to use function to insert nodes into the avl tree
 *
 * Inputs:
 * 	node **root: the pointer to adjust the root if necessary
 * 	node *to_insert: the node that is to be entered
 * 	CompareFunc: the function that will be used to compare in tree
 * Outputs: n/a
 ********************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 *******************************************************************************/
void insert(node **root, void *to_insert, CompareFunc compare) {
  node *insert_node = make_node(to_insert);
  if (*root == NULL) {
    *root = insert_node;
  } else {
    *root = rec_insert(insert_node, *root, compare);
  }
}

/*******************************************************************************
 * Function Title: make_node
 * Summary: this function creates a node.
 *
 * Inputs:
 * 	void *data: the data to be inserted
 * Outputs:
 * 	node *: the newly created node.
 ********************************************************************************
 * Pseudocode
 *   Begin
 *			allocate memory for new node
 *			save data pointer in node
 *			set height to zero
 *			set left and right pointers to NULL
 *   End
 *******************************************************************************/
node *make_node(void *data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->height = 0;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

/*******************************************************************************
 * Function Title: find_min
 * Summary: This function finds the smallest data variable. 'farthest left'
 * Inputs:
 * 	node *root: the starting point to look from
 * Outputs:
 *		node *: the smallest node
 ********************************************************************************
 * Pseudocode
 *   Begin
 *			if node passed to function is null
 *				return NULL
 *			loop while node isn't the smallest
 *			return smallest
 *   End
 *******************************************************************************/
node *find_min(node *root) {
  if (NULL == root) {
    return NULL;
  }
  for (; root->left != NULL; root = root->left)
    ;
  return root;
}

/*******************************************************************************
 * Function Title: delete_min
 * Summary: This function deletes the node with the smallest data value
 *
 * Inputs:
 * 	node *root: the root of the tree to delete min value from
 * Outputs: n/a
 ********************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 *******************************************************************************/
node *delete_min(node *root) {
  if (root->left != NULL) {
    root = rec_delete_min(root);
  } else {
    printf("root: %p\tl: %p\tr: %p\n", root, root->left, root->right);
  }
  return root;
}

/*******************************************************************************
 * Function Title: find_max
 * Summary: This function locates the node with the largest data member
 *
 * Inputs:
 * 	node *root: the node to start looking from
 * Outputs:
 * 	node *: the 'largest' node
 ********************************************************************************
 * Pseudocode
 *   Begin
 *			if node passed to function is null
 *				return NULL
 *			loop while node isn't the biggest
 *			return biggest
 *   End
 *******************************************************************************/
node *find_max(node *root) {
  if (NULL == root) {
    return NULL;
  }
  for (; root->right != NULL; root = root->right)
    ;
  return root;
}

/*******************************************************************************
 * Function Title: delete_max
 * Summary: This function deletes the largest data node
 *
 * Inputs:
 * 	node *root: the root of the tree to delete the max value from
 * Outputs:
 * 	node *: the new root if it changed
 ********************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 *******************************************************************************/
node *delete_max(node *root) {
  if (root->right != NULL) {
    root = rec_delete_max(root);
  } else {
    printf("root: %p\tl: %p\tr: %p", root, root->left, root->right);
  }
  return root;
}

/*******************************************************************************
 * Function Title: print_tree
 * Summary: This function prints out the tree
 *
 * Inputs:
 * 	node *root: the starting point of the print
 * 	PrintFunc print: the way the function should print
 * 	FILE *dest: the destination to print to ex: stdout
 * Outputs: n/a
 ********************************************************************************
 * Pseudocode
 *   Begin
 *   	if tree is empty
 *   		print empty tree
 *   	else
 *				call rec_print
 *   End
 *******************************************************************************/
void print_tree(node *tree, PrintFunc print, FILE *dest) {
  if (NULL == tree) {
    fprintf(dest, "Empty Tree\n");
  } else {
    rec_print(tree, print, dest, 0);
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//		Below are helper function definitions
//
///////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
 * Function Title: rec_remove
 * Summary: a helper function to recursively remove a node in the tree,
 *					 given the data.
 * Inputs:
 * 	node *curr: the current node being examined
 * 	node *to_delete: a node that we want to delete from tree
 * 	CompareFunc: the function used to correctly compare the nodes
 * Outputs:
 * 	node *: a pointer to a node to ensure tree balance
 ********************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 *******************************************************************************/
node *rec_remove(node *curr, node *to_delete, CompareFunc compare) {
  if (curr == NULL)
    return curr;
  int compare_res = compare(to_delete, curr);
  if (compare_res < 0) { // if to_delete is smaller go left
    curr->left = rec_remove(curr->left, to_delete, compare);
  } else if (compare_res > 0) { // if to_delete is bigger go right
    curr->right = rec_remove(curr->right, to_delete, compare);
  } else {                                           // node found
    if (curr->left != NULL && curr->right != NULL) { // with 2 kids find small
      node *min;
      void *temp_data;
      min = find_min(curr->right); // find smallest node
      temp_data = curr->data;      // save temp node
      curr->data = min->data;      // set curr data to be min->data
      min->data = temp_data;       // set curr
      curr->right = rec_remove(curr->right, to_delete, compare);
    } else {
      // set curr to be the correct pointer (a child node or NULL)
      node *temp = curr;
      curr = (curr->left != NULL) ? curr->left : curr->right;
      // free the unnecessary memory
      free(temp->data);
      free(temp);
      temp = NULL;
    }
  }
  return balance(curr);
}

/*******************************************************************************
 * Function Title:	rec_insert
 * Summary: this function inserts nodes into the tree
 *
 * Inputs:
 * 	node *new_node: The node to be inserted
 * 	CompareFunc: function pointer telling how to compare node data types
 * Outputs:
 *
 ********************************************************************************
 * Pseudocode
 *		Begin
 *			create compare int
 *			if node to insert is null
 *				print error
 *				insert curr to tree
 *			if new_node is equal to the node to insert
 *				free the memory for the node data
 *				free the memory for the node
 *				set the node to null to prevent bad access
 *				insert curr to tree
 *			if curr is null
 *				insert new node to the tree
 *			set conpare int
 *			if new_node is smaller
 *				insert to the left
 *			else
 *				insert to the right
 *			return a balanced subtree
 *   	End
 *******************************************************************************/
node *rec_insert(node *new_node, node *curr, CompareFunc compare) {
  int compare_results;
  if (NULL == new_node) {
    printf("ERROR: cannot insert nothing!\n");
    return curr;
  }
  if (compare(new_node, curr) == 0) {
    free(new_node->data);
    free(new_node);
    new_node = NULL;
    return curr;
  }
  if (NULL == curr) {
    return new_node;
  }
  compare_results = compare(curr, new_node);
  if (compare_results > 0) { // if the results are smaller go left
    curr->left = rec_insert(new_node, curr->left, compare);
  } else { // else go right
    curr->right = rec_insert(new_node, curr->right, compare);
  }
  return balance(curr);
}

/*******************************************************************************
 * Function Title: rec_print
 * Summary: this function is a helper function that uses recursion to print the
 * 				 AVL tree
 * Inputs:
 * 	node *curr: the "current" node to print
 *		PrintFunc print: the function that correctly prints the node
 *		FILE *dest: the destination to print to.
 *		int spaces: an integer responsible for the indentation of the print
 * Outputs: n/a
 ********************************************************************************
 * Pseudocode
 *   Begin
 *			if the current node isn't null
 *				print the right side of the tree
 *				print the current node
 *				print the left side of the tree
 *   End
 *******************************************************************************/
void rec_print(node *curr, PrintFunc print, FILE *dest, int spaces) {
  int i;
  if (NULL != curr) {
    if (curr->left != NULL)
      rec_print(curr->left, print, dest, spaces + 4);
    for (i = 0; i < spaces; ++i)
      fprintf(dest, " ");
    print(curr, dest);
    fprintf(dest, "\n");
    if (curr->right != NULL)
      rec_print(curr->right, print, dest, spaces + 4);
  }
}

/*******************************************************************************
 * Function Title: balance
 * Summary: this function balances the AVL tree
 *
 * Inputs:
 * 		node *curr: the node that should be balanced
 * Outputs:
 * 		node *: a pointer to the new `root` of the subtree
 *******************************************************************************
 * Pseudocode
 *   Begin
 *			if curr is null then
 *				return NULL
 *			if left is too heavy
 *				if left left is heavier
 *					perform one right rotation
 *				else
 *					perform double right rotation
 *			if right is too heavy
 *				if right right is heavier
 *					perform single left rotation
 *				else
 *					perform double right rotation
 *   End
 ******************************************************************************/
node *balance(node *curr) {
  int temp_l = 0, temp_r = 0;
  if (NULL == curr)
    return curr;
  if (height(curr->left) - height(curr->right) > ALLOWED_IMBALANCE) {
    temp_l = height(curr->left->left);
    temp_r = height(curr->left->right);
    if (temp_l >= temp_r) {
      // do single right rotation
      curr = one_right_rotation(curr);
    } else {
      // do double right rotation
      curr = two_right_rotation(curr);
    }
  } else if (height(curr->right) - height(curr->left) > ALLOWED_IMBALANCE) {
    temp_l = height(curr->right->left);
    temp_r = height(curr->right->right);
    if (temp_r >= temp_l) {
      // do single left rotation
      curr = one_left_rotation(curr);
    } else {
      // do double left rotation
      curr = two_left_rotation(curr);
    }
  }
  curr->height = (height(curr->left) > height(curr->right))
                     ? height(curr->left)
                     : height(curr->right);
  curr->height += 1;
  return curr;
}

/*******************************************************************************
 * Function Title: one_right_rotation
 * Summary: this performs a single right rotation
 *
 * Inputs:
 * 	node *to_rotate: this is the node that needs rotating
 * Outputs:
 * 	node *: this is a node pointer that is to the newly arranged nodes
 ********************************************************************************
 * Pseudocode
 *   Begin
 *			assign the correct node to be the 'root' or the node that is returned
 *			correctly save the node that could get lost
 *			complete the rotation
 *			fix to_rotate's height
 *			fix new_root's height
 *   End
 *******************************************************************************/

// CHECK NULL POINTERS!! This could segfault
node *one_right_rotation(node *to_rotate) {
  node *new_root = to_rotate->left;  // assigns nodes with correct 'root'
  to_rotate->left = new_root->right; // prevents data loss in switch
  new_root->right = to_rotate;       // completes the movement of nodes
  // fix to_rotate's height
  if (height(to_rotate->left) >= height(to_rotate->right)) {
    to_rotate->height = height(to_rotate->left) + 1;
  } else {
    to_rotate->height = height(to_rotate->right) + 1;
  }
  // fix new_root's height
  if (height(new_root->left) >= height(to_rotate)) {
    new_root->height = height(to_rotate) + 1;
  } else {
    new_root->height = height(to_rotate) + 1;
  }
  // return the rotated nodes
  return new_root;
}

/*******************************************************************************
 * Function Title: one_left_rotation
 * Summary: this performs a single left rotation
 *
 * Inputs:
 * 	node *to_rotate: this is the node that needs rotating
 * Outputs:
 * 	node *: this is a node pointer that is to the newly arranged nodes
 ********************************************************************************
 * Pseudocode
 *   Begin
 *			assign the correct node to be the 'root' or the node that is returned
 *			correctly save the node that could get lost
 *			complete the rotation
 *			fix to_rotate's height
 *			fix new_root's height
 *   End
 *******************************************************************************/

// CHECK NULL POINTERS!! This could segfault
node *one_left_rotation(node *to_rotate) {
  node *new_root = to_rotate->right; // create temp node to return;
  to_rotate->right = new_root->left; // prevent data loss in rotation
  new_root->left = to_rotate;
  if (height(to_rotate->left) >= height(to_rotate->right)) {
    to_rotate->height = height(to_rotate->left) + 1;
  } else {
    to_rotate->height = height(to_rotate->right) + 1;
  }
  if (height(new_root->right) >= height(to_rotate)) {
    new_root->height = height(new_root->right);
  } else {
    new_root->height = height(to_rotate);
  }
  return new_root;
}

/*******************************************************************************
 * Function Title: two_right_rotation
 * Summary: this function performs a double right rotation as a helper function
 * 				 for the balance function.
 * Inputs:
 * 	node *to_rotate: the node that needs rotated
 * Outputs:
 * 	node*: the pointer to the newly balanced node
 ********************************************************************************
 * Pseudocode
 *   Begin
 *			left rotate to_rotate's left node.
 *			right rotate to_rotate
 *   End
 *******************************************************************************/
node *two_right_rotation(node *to_rotate) {
  to_rotate->left = one_left_rotation(to_rotate->left);
  return one_right_rotation(to_rotate);
}

/*******************************************************************************
 * Function Title: two_left_rotation
 * Summary: this function persforms a double right rotation as a helper function
 * 				 for the balnace function.
 * Inputs:
 * 	node *to_rotate: the node htat needs rotated
 * Outputs:
 * 	node*: the pinter to the newly balanced node
 ********************************************************************************
 * Pseudocode
 *   Begin
 *			right rotate to_rotate's right node
 *			left rotate to_rotate
 *   End
 *******************************************************************************/
node *two_left_rotation(node *to_rotate) {
  to_rotate->right = one_right_rotation(to_rotate->right);
  return one_left_rotation(to_rotate);
}

/*******************************************************************************
 * Function Title: height
 * Summary: this function gets the correct height of a node
 *
 * Inputs:
 * 	node *t: the nod in question
 * Outputs:
 *		int: the value of the height
 ********************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 *******************************************************************************/
int height(node *node) {
  if (NULL == node) {
    return -1;
  } else
    return node->height;
}

/*******************************************************************************
 * Function Title: rec_delete_min
 * Summary: this is a recursive helper function that gets to the farthest left
 * 			    node, and then deletes it.
 * Inputs:
 * 	node *curr: the current node
 * Outputs:
 * 	node *: a pointer to the currect node, so deleted node gets set to null
 ********************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 *******************************************************************************/
node *rec_delete_min(node *curr) {
  if (curr->left != NULL) {
    curr->left = rec_delete_min(curr->left);
  } else {
    if (curr->right != NULL) { // if ever there is data pointed to by most left
      curr->left = rec_delete_min(curr->right);
    } else {
      free(curr->data);
      free(curr);
      curr = NULL;
    }
  }
  return balance(curr);
}

/*******************************************************************************
 * Function Title: rec_delete_max
 * Summary: this recursive helper function finds the farthest right node, and
 * 				 then deletes it.
 * Inputs
 * 	node *curr: the current node
 * Outputs:
 * 	node *: a pointer to the current node, so deleted node gets set to null
 *******************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 ******************************************************************************/
node *rec_delete_max(node *curr) {
  if (curr->right != NULL) {
    curr->right = rec_delete_max(curr->right);
  } else {
    if (curr->left != NULL) { // if there is data pointered to by most right
      curr->right = rec_delete_max(curr->left);
    } else {
      free(curr->data);
      free(curr);
      curr = NULL;
    }
  }
  return balance(curr);
}

///////////////////////////////////////////////////////////////////////////////
///
///		Below are the CompareFunc Definitions
///
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
 *	Compare integer function
 *****************************************************************************/
int compare_int(const node *left, const node *right) {
  if (NULL == left || NULL == right) {
    // printf("ERROR: don't pass NULL to compare; compare_int\n");
    return 45;
  }
  int l = *(int *)left->data;
  int r = *(int *)right->data;
  return (l > r) - (l < r);
}

/******************************************************************************
 *	Compare character function
 *****************************************************************************/
int compare_char(const node *left, const node *right) {
  if (NULL == left || NULL == right) {
    // printf("ERROR: don't pass NULL to compare; compare_char\n");
    return 45;
  }
  if (*(char *)left->data > *(char *)right->data) {
    return 1;
  } else if (*(char *)left->data < *(char *)right->data) {
    return -1;
  }
  return 0;
}

/******************************************************************************
 *	Compare float function
 *****************************************************************************/
int compare_float(const node *left, const node *right) {
  if (NULL == left || NULL == right) {
    // printf("ERROR: don't pass NULL to compare; compare_float\n");
    return 45;
  }
  if (*(float *)left->data > *(float *)right->data) {
    return 1;
  } else if (*(float *)left->data < *(float *)right->data) {
    return -1;
  }
  return 0;
}

/******************************************************************************
 *	Compare double function
 *****************************************************************************/
int compare_double(const node *left, const node *right) {
  if (NULL == left || NULL == right) {
    // printf("ERROR: don't pass NULL to compare; compare_double\n");
    return 45;
  }
  if (*(double *)left->data > *(double *)right->data) {
    return 1;
  } else if (*(double *)left->data < *(double *)right->data) {
    return -1;
  }
  return 0;
}

/******************************************************************************
 *	Compare string function
 *****************************************************************************/
int compare_string(const node *left, const node *right) {
  if (NULL == left || NULL == right) {
    // printf("ERROR: don't pass NULL to compare; compare_float\n");
    return 45;
  }
  if (strcmp((char *)left->data, (char *)right->data) > 0) {
    return 1;
  } else if (strcmp((char *)left->data, (char *)right->data) < 0) {
    return -1;
  }
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
///
///		Below are the PrintFunc Definitions
///
//////////////////////////////////////////////////////////////////////////////

/******************************************************************************
 *	print_integer function (node *to_print, FILE *dest)
 *****************************************************************************/
void print_int(node *to_print, FILE *dest) {
  if (NULL == to_print) {
    printf("ERROR: cannot print NULL node; print_int-%p\n", to_print);
    return;
  }
  if (NULL == dest) {
    printf("ERROR: don't pass NULL file pointers; print_int-%p\n", dest);
    return;
  }
  if (to_print->data == NULL) {
    fprintf(dest, "(d: NULL");
  } else {
    fprintf(dest, "(d: %d,", *(int *)to_print->data);
  }
  fprintf(dest, "h: %d)", to_print->height);
}

/******************************************************************************
 *	print_char function (node *to_print, FILE *dest)
 *****************************************************************************/
void print_char(node *to_print, FILE *dest) {
  if (NULL == to_print) {
    printf("ERROR: cannot print NULL node; print_char\n");
    return;
  }
  if (NULL == dest) {
    printf("ERROR: don't pass NULL file pointers; print_char\n");
    return;
  }
  fprintf(dest, "(d: %c,", *(char *)to_print->data); // d(data):
  fprintf(dest, "h: %d)", to_print->height);         // h(height):
}

/******************************************************************************
 *	print_float function (node *to_print, FILE *dest)
 *****************************************************************************/
void print_float(node *to_print, FILE *dest) {
  if (NULL == to_print) {
    printf("ERROR: cannot print NULL node; print_float\n");
    return;
  }
  if (NULL == dest) {
    printf("ERROR: don't pass NULL file pointers; print_float\n");
    return;
  }
  fprintf(dest, "(d: %f,", *(float *)to_print->data);
  fprintf(dest, "h: %d)", to_print->height);
}

/******************************************************************************
 *	print_double function (node *to_print, FILE *dest)
 *****************************************************************************/
void print_double(node *to_print, FILE *dest) {
  if (NULL == to_print) {
    printf("ERROR: cannot print NULL node; print_double\n");
    return;
  }
  if (NULL == dest) {
    printf("ERROR: don't pass NULL file pointers; print_double\n");
    return;
  }
  fprintf(dest, "(d: %lf,", *(double *)to_print->data);
  fprintf(dest, "h: %d)", to_print->height);
}

/******************************************************************************
 *	print_string function (node *to_print, FILE *dest)
 *****************************************************************************/
void print_string(node *to_print, FILE *dest) {
  if (NULL == to_print) {
    printf("ERROR: cannot print NULL node; print_string\n");
    return;
  }
  if (NULL == dest) {
    printf("ERROR: don't pass NULL file pointers; print_string\n");
    return;
  }
  fprintf(dest, "(d: %s,", (char *)to_print->data);
  fprintf(dest, "h: %d)", to_print->height);
}

/******************************************************************************
 *	print_integer function (node *to_print, FILE *dest)
 *****************************************************************************/
void print_int2(node *to_print, FILE *dest) {
  if (NULL == to_print) {
    printf("ERROR: cannot print NULL node; print_int-%p\n", to_print);
    return;
  }
  if (NULL == dest) {
    printf("ERROR: don't pass NULL file pointers; print_int\n");
    return;
  }
  if (to_print->data == NULL) {
    fprintf(dest, "(NULL");
  } else {
    fprintf(dest, "(%d,", *(int *)to_print->data);
  }
  fprintf(dest, "%d)", height(to_print));
}
