A milti-way existence trie examines more that 1 bit at a time. The tradeoff
is that for each R bits considered, tree nodes contain 2^R links.

R-ary tries improve search and insert speed at the expense of extra space
for links and a limited set of functions. This implementation only has
search and insert. The delete, sort, and select functions can be written
but they will perform poorly.

This implementation uses variable length strings as keys. It assumes no
key is a prefix for another.
