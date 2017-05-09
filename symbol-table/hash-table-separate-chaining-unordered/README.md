Utilized "separate chaining" to resolve hash colisions. Each table index
points to a linked list that hols all items whos keys hash to the same
index.

Hash tables are preferred over binary trees for their near-optimal search
times, assuming a good hash algorithm is available.

This unordered hash table implementation is generally preferred over the
ordered hash table when separate chaining is used, because all operations
are sufficiently fast for most applications. Ordered lists are usually
preferred when sort and select operations are required.
