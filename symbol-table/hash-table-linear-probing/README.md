This is a has table that uses linear probing for collision resolution. It
uses an array roughly two times as large as the expected number of items
to be inserted, and relies on empty places to resolve collisions.

Linear probing is not apropriate for implementations that require select
and sort operations.

In general, linear probing is faster than separate chaining, but takes more
space due to the use of empty spots in the table.
