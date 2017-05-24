NOTE!! This code is incomplete. Do not use!

Extendable hashing is part of a set of data structures and algorithms 
used for extrernal searching. This code is meant to be used to access data
stored on files on disk.

This serves as the basis for many modern data programs.

Before it can be used, this code has to be modified to read and refer to
disk files. Further, it should be tuned for the characteristics of the
hardware running the code.

Extendable hashing combines features of hashing, multi-way tries, and
sequential access methods.

Extendable hashing maintains a directory that tells us where we can find
the page containing items that match the search key.
