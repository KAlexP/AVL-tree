# AVL-tree

An AVL tree written in c. ___Not complete___

<a id="table-of-contents"></a>
## Table of Contents 
- [Installation](#installation)
- [Formatting](#formatting)
- [Usage](#usage)
- [Unit Testing](#unit-testing)
- [License](#license)

<a id="installation"></a>
## Installation

1. Clone the repository 

```bash 
git clone git@github.com:KAlexP/AVL-tree
```

2. Install dependancies

For macOS use

```bash
brew install cunit
```

For other platforms here is the CUnit git repo:

```bash
git@github.com:jacklicn/CUnit.git
```

<a id="formatting"></a>
## Formatting

This project uses `clang-format` to enforce consistent C/C++ style.

### How to format
- Install `clang-format`
- Use the provided `.clang-format` file
- You can auto-format with:

```bash
clang-format -i file_name.c
```

Depending on your IDE there are ways to automate the code formatting.

<a id="usage"></a>
## Usage 

___Word of Warning___: If you don't understand pointers be cautious using this 
code. To insert data into the tree you should follow a few steps.

1. Allocate new memory for `void *to_insert` data correctly. This is important or you 
will get confusing errors that aren't easy to debug. If you want to use a `double` 
for example you would need write `to_insert = malloc(sizeof(double));`.

2. Correctly assign the data to `void *to_insert` data. You need to cast the `void *to_insert` as 
the type you are trying to assign it to be when you insert the data. You could write 
something that looks like `*(double *)to_insert = 3.1415926535`. 

3. Create a new node. Use the function `make_node` to create a new node. You pass 
the `void *` variable you have into the function and it handles the memory allocation 
of each individual node, and assigns the other values correctly. 

4. Insert the node into the tree. You will use a function to insert into the tree. 
I have provided with the code `void insert(node **root, node *to_insert, CompareFunc compare);` 
to make insertion easier. You must use the address of the pointer to the root node in order for 
the function to work correctly.

Below is an example of the tree getting used for integers. This tree allows several data 
types by default. You can expand the tree to support other data types by creating 
`CompareFunc` and `PrintFunc` functions. Examples can be found in `AVLtree.c`

```c 
	#include "AVLtree.H"
	#include <time.h>

	int main(int argc, char **argv){
		node *root = AVLtree();
		node *temp_node;
		srand(time(NULL));
		void *to_insert;
		for(int itr=0;itr < 15; ++itr){
			to_insert = malloc(sizeof(int));
			*(int *)to_insert = rand();
			temp_node = make_node(to_insert);
			insert(&root,temp_node,compare_int);
		}
		print_tree(root, print_int, stdout);
		avl_free(root);
		return 0;
	}
```

If you get a ``use after free'' error after trying to insert a new node, you may 
have forgotten to allocate new memory to `void *to_insert`. 

<a id="unit-testing"></a>
## Unit Testing

This project uses cunit test framework for testing. Documentation can be found 
in the link below. Installation instructions can be found above in [Installation](#installation).

[https://cunit.sourceforge.net/doc/index.html](https://cunit.sourceforge.net/doc/index.html)

<a id="license"></a>
## License
This project is licensed under ...

[table of contents](#table-of-contents)
