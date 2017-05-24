A B Tree is part of a set of data structures used for extrernal searching.
This code is meant to be used to access data stored on files on disk.

A B Tree serves as the basis for many modern data programs.

Before it can be used, this code has to be modified to read and refer to
disk files. Further, it should be tuned for the characteristics of the
hardware running the code.

A B Tree is a multi-way tree that dynamically and efficiently grows as the
data stored is increased. It can potentially store millions of records, and
provide quick search and insert capabilities.

Select, sort, and delete operations are supported, however their execution
is less efficient that search and insert.

The delete operation that is implemented assumed that the number of delete
operations will be somewhat equal to or less than the number of inserts,
and that the database will not undergo a large contraction (large number
of deletes). If large contractions are necessary, the delete function may
need to be optimized to free up table space more effectively.
