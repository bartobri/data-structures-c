This randomized BST makes a random decision to insert a node at the root.
Otherwise, it is inserted into the left or right subtree, where the
random-root-insert decision is again made. This happens for each level
of the tree until the node is inserted.

This algorithm provides protection against poorly balanced trees, if for
example the keys are inserted in order, without the overhead of more
expensive balancing techniques. One of the main drawbacks is the cost of
generating a random number for every insertion.
