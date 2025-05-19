# AVL-tree

An AVL tree written in c

<a id="table-of-contents"></a>
## Table of Contents 
- [Installation](#installation)
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

<a id="usage"></a>
## Usage 

This AVL tree is a general purpose AVL tree. It stores the data as `void *`	in 
the tree, as such the user needs to correctly allocate memory for the data 
to be stored. Data types that already have support are `char, int, float, double, char *, double complex`

Below is an example of how to use in your own code.

```c 
	#include "AVLtree.H"
	#include <time.h>

	int main(int argc, char **argv){
		node *root = AVLtree();
		node *temp_node;
		srand(time(NULL));
		void *to_insert = malloc(sizof(int));
		for(int itr=0;itr < 15; ++itr){
			*(int *)to_insert = rand();
			temp_node = make_node(to_insert);
			root = insert(temp_node,compare_int);
		}
		print_tree(root, print_int, stdout);
		avl_free(root);
		return 0;
	}
```

<a id="unit-testing"></a>
## Unit Testing

This project uses cunit test framework for testing. Documentation can be found 
in the link below. Installation instructions can be found above in [Installation](#installation).

[https://cunit.sourceforge.net/doc/index.html](https://cunit.sourceforge.net/doc/index.html)

<a id="license"></a>
## License
This project is licensed under ...

[table of contents](#table-of-contents)
