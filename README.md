# AVL-tree

An AVL tree written in c

## Table of Contents 
- [Installation](#installation)
- [Usage](#usage)
- [Unit Testing](#unit-testing)
- [License](#license)

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

## Usage 

This AVL tree is a general purpose AVL tree. It stores the data as `void *`	in 
the tree, as such the user needs to correctly allocate memory for the data 
to be stored. Data types that already have support are `char,int,float,double,char *, double complex`

To start the AVL tree you should perform the following actions

```c 
	node *root = AVLtree();
```

## Unit Testing

This project uses cunit test framework for testing. Documentation can be found 
in the link below. Installation instructions can be found above in [Installation](#installation).

[https://cunit.sourceforge.net/doc/index.html](https://cunit.sourceforge.net/doc/index.html)

## License
This project is licensed under ...
