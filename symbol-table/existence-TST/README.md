TST = Ternary Search Trie

This implementation uses variable length strings as keys. It assumes no
key is a prefix for another.

Each node in a TST has a character and 3 links, sorresponding to keys
whose current digits are less than, equal to, or greater than the node's
character.

TSTs adapt gracefully to irregularities in search keys. With TSTs we can
use 128-256 character encoding without the worry of excessive cost of
node branching such as with multi-way tries. TSTs are especially apropriate
for multi-byte character sets.

Search misses are likely to be extremely efficient.
