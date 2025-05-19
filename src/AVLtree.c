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
node* AVLtree(void){
	return NULL;
}


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
void avl_free(node *root){					//	Begin
	node *temp = root;								//		set up temp variable
	if(temp->left != NULL){						//		if there is a left child
		avl_free(temp->left);			//			recursively call delete on left 
	}
	if(temp->right != NULL){					//		if there is a right child
		avl_free(temp->right);		//			recursively call delete on right
	}
	free(temp->data);									//		free the data memory
	free(temp);												//		free the node memory
	return; 
}																		//	End


/*******************************************************************************
* Function Title:	insert
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
void insert(node *new_node,CompareFunc compare){

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
node* make_node(void *data){
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
node* find_min(node *root){
	if(NULL == root){
		return NULL;
  }
  for(;root->left != NULL;root = root->left);
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
void delete_min(void){

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
node* find_max(node *root){
	if(NULL == root){
		return NULL;
  }
	for(;root->right != NULL; root = root->right);
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
void delete_max(void){

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
void print_tree(node *tree, PrintFunc print, FILE *dest){
	if(NULL == tree){
		fprintf(dest,"Empty Tree\n");
  } else {
		rec_print(tree,print,dest,0);
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//		Below are helper function definitions
//
///////////////////////////////////////////////////////////////////////////////


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
void rec_print(node *curr, PrintFunc print, FILE *dest, int spaces){
	if(NULL != curr){
		rec_print(curr,print,dest,spaces + 4);
    for(int i = 0; i < spaces; ++i) fprintf(dest," ");
    print(curr,dest);
    rec_print(curr,print,dest,spaces + 4);
  }
}


///////////////////////////////////////////////////////////////////////////////
///
///		Below are the CompareFunc Definitions
///
///////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////
///
///		Below are the CompareFunc Definitions
///
///////////////////////////////////////////////////////////////////////////////
