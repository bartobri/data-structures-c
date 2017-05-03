A BST with splay insertion inserts new nodes at the root of the tree.
However, it differs from standard root insertion in that it performs two
tree rotations (instead of just one as with the standard root insertion
method) to place the new node at the root of the tree. The type or
rotation executed depends on the orientation of links between the new node
and it's grandfather.

Splay insertion eliminates the quadratic worst case that can occur with
standard BSTs.
