
<h2><b>STL map:</b></h2>

- STL maps uses balanced binary tree esp red and black tree

- Good for range retrival or search



<h2><b>Unordered map:</b></h2>

- Internally, the elements in the unordered_map are not sorted in any particular order with respect to either their key or mapped values, but organized into buckets depending on their hash values to allow for fast access to individual elements directly by their key values (with a constant average time complexity on average).

- unordered_map containers are faster than map containers to access individual elements by their key, although they are generally less efficient for range iteration through a subset of their elements.

- Faster than STL maps and works better in larger set.

## HashMap implementation
    * A bucket is one element of HashMap array. It is used to store nodes
    * Two or more nodes can have the same bucket. In that case link list structure is used to connect the nodes
    * Buckets are different in capacity. A relation between bucket and capacity is as follows:
        capacity = number of buckets * load factor
