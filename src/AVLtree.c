#include "AVLtree.h"

///////////////////////////////////////////////////////////////////////////////
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
 *			free the data memory
 *			free the node memory
 *   End
 *******************************************************************************/
void avl_free(node *root) { //	Begin
  node *temp = root;        //		set up temp variable
  if (temp->left != NULL) { //		if there is a left child
    avl_free(temp->left);   //			recursively call delete on left
  }
  if (temp->right != NULL) { //		if there is a right child
    avl_free(temp->right);   //			recursively call delete on right
  }
  free(temp->data); //		free the data memory
  free(temp);       //		free the node memory
  return;
} //	End

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
 * Inputs: n/a
 * Outputs: n/a
 ********************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 *******************************************************************************/
void delete_min(void) {}

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
 * Inputs: n/a
 * Outputs: n/a
 ********************************************************************************
 * Pseudocode
 *   Begin
 *
 *   End
 *******************************************************************************/
void delete_max(void) {}

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
 *   Begin
 *
 *   End
 *******************************************************************************/
node *rec_insert(node *new_node, node *curr, CompareFunc compare) {
  if (NULL == new_node) {
    printf("ERROR: cannot insert nothing!\n");
    return NULL;
  }
  int compare_results = compare(curr, new_node);
  if (compare_results < 0) {
    curr->left = rec_insert(new_node, curr->left, compare);
  } else {
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
  if (NULL != curr) {
    rec_print(curr, print, dest, spaces + 4);
    for (int i = 0; i < spaces; ++i)
      fprintf(dest, " ");
    print(curr, dest);
    rec_print(curr, print, dest, spaces + 4);
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
  if (curr->left->height - curr->right->height > ALLOWED_IMBALANCE) {
    temp_l = curr->left->left->height;
    temp_r = curr->left->right->height;
    if (temp_l >= temp_r) {
      // do single right rotation
      curr = one_right_rotation(curr);
    } else {
      // do double right rotation
      curr = two_right_rotation(curr);
    }
  } else if (curr->right->height - curr->left->height > ALLOWED_IMBALANCE) {
    temp_l = curr->right->left->height;
    temp_r = curr->right->right->height;
    if (temp_r >= temp_l) {
      // do single left rotation
      curr = one_left_rotation(curr);
    } else {
      // do double left rotation
      curr = two_left_rotation(curr);
    }
  }
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
  if (to_rotate->left->height >= to_rotate->right->height) {
    to_rotate->height = to_rotate->left->height + 1;
  } else {
    to_rotate->height = to_rotate->right->height + 1;
  }
  // fix new_root's height
  if (new_root->left->height >= to_rotate->height) {
    new_root->height = to_rotate->height + 1;
  } else {
    new_root->height = to_rotate->height + 1;
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
  if (to_rotate->left->height >= to_rotate->right->height) {
    to_rotate->height = to_rotate->left->height + 1;
  } else {
    to_rotate->height = to_rotate->right->height + 1;
  }
  if (new_root->right->height >= to_rotate->height) {
    new_root->height = new_root->right->height;
  } else {
    new_root->height = to_rotate->height;
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
    printf("ERROR: don't pass NULL to compare; compare_int\n");
    return 0;
  }
  if (*(int *)left->data > *(int *)right->data) {
    return 1;
  } else if (*(int *)left->data < *(int *)right->data) {
    return -1;
  }
  return 0;
}

/******************************************************************************
 *	Compare character function
 *****************************************************************************/
int compare_char(const node *left, const node *right) {
  if (NULL == left || NULL == right) {
    printf("ERROR: don't pass NULL to compare: compare_char\n");
    return 0;
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
    printf("ERROR: don't pass NULL to compare: compare_float\n");
    return 0;
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
    printf("ERROR: don't pass NULL to compare: compare_double\n");
    return 0;
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
    printf("ERROR: don't pass NULL to compare: compare_float\n");
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

void print_int(node *to_print, FILE *dest) {
  if (NULL == to_print) {
    printf("ERROR: cannot print NULL node! --print_int--\n");
    return;
  }
  if (NULL == dest) {
    printf("ERROR: don't pass NULL file pointers! --print_int--\n");
    return;
  }
  fprintf(dest, "(data: %d  ", *(int *)to_print->data);
  fprintf(dest, "height: %d)", to_print->height);
}
