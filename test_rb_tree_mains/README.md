#RB_TREE library test:

## introduction:
To get an example of the power of this library, i created an example of a
red black tree that contains elements of different types. Use the program in
main_polymorphism.c to have a visual of the example.

compile it, then execute it (unzoom screen enough to see the clouds of colour
distincly).

## usage:
### compile:
cp ../libft/libft.h ./ && cp ../bstree/bstree.h ./ && cp ../rb_tree/rb_tree.h ./ && \
gcc ../bstree/*.c ../libft/*.c ../rb_tree/*.c main_polymorphism.c

### launch:
./a.out

## what main_polymorphism does in a nutshell.

We add three different types of data. (each have a specific enum, which will be
represented by a specific color).

we will add randomly elements with a specific value, which will be one of the
three basic types of data(either one of the three colors).

then will will apply a uniq() function, to make sure there is never twice the
same element in the three.

We will also extract the elements of a certain type, building a new subtree.
(each subtree being of a specific color).

We will do this twice

we will print out the subtrees(each have its own color), and the remaining tree
(which should have the elements of the remaining color that did not get
extracted in a subtree).


## main_polymorphism program explained:

Basically each node of the tree can contain a void* pointer.
We decide that this void* pointer will refer to a structure with:
- an enum representing a type ID (used to have a specific ID for each type).
- the data itself

The first field of the structure will help us identify the type, then for a 
given type we can access the data. This allows us to have some polymorphism in
our tree, always looking at the first part of the structure (the enum), then
knowing what we are refering to

In this program i will add elements of different types to a rb_tree.

The elements of same types will be adjacent to each other in the tree.
So the types are not mixed up. We can see "clouds" of elements of the same type
here represented by a different color.
This is achieved with a custom cmp function, and each type being assigned a
value through an general enum.
(so ID goes from 0, 1, 2, ... to "number of types")

For a given specific type: each elements are sorted, still with the same custom
cmp function. Have a look at the cmp_func definition in main_polymorphism.c to 
get an idea of the cmp function code.

Also have a loook at the comments in the rb_tree_add function to get an idea
of the condition to always add to take care of nodes containing NULL.
