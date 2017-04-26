For key values that are too large to be used as array indices. This symbol
table implementation keeps an ordered linked list. An ordered linked list provides a
slower insert, but because the list is ordered, the functions select and
sort are available. Search still takes the same time as an unordered linked
list, so only use this if you need a list-based symbol table with select
and sort functions.
