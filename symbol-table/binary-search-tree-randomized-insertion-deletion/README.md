This randomized BST makes a random decision to insert a node at the root.
Otherwise, it is inserted into the left or right subtree, where the
random-root-insert decision is again made. This happens for each level
of the tree until the node is inserted.

This algorithm also makes a randomized decision to choose the new root
(right or left subtree) when a node is deleted.

This algorithm provides protection against poorly balanced trees. Keys
can be inserted in any order, and the randomized insert/delete algorithm
is the equivilent of inserting the keys in random order.

One of the main drawbacks is the cost of generating a random number for
every insertion/deletion.
