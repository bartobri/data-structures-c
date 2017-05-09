Utilized "separate chaining" to resolve hash colisions. Each table index
points to a linked list that hols all items whos keys hash to the same
index.

Hash tables are preferred over binary trees for their near-optimal search
times, assuming a good hash algorithm is available.
