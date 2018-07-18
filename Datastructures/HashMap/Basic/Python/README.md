## Python version of hashmap is dict


```python
>>> a = dict(one=1, two=2, three=3)
>>> b = {'one': 1, 'two': 2, 'three': 3}
>>> c = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
>>> d = dict([('two', 2), ('one', 1), ('three', 3)])
>>> e = dict({'three': 3, 'one': 1, 'two': 2})
>>> a == b == c == d == e
True
```

 ```
d[key] = value - Assign value
get(key[, default]) - return value if present otherwise default
key in d - return true if key is present
del d[key] - delete entry. Raises a KeyError if key is not in the map.
iter(d) - iterate over key 
copy() - shallow copy
clear() - removes all items
len - number of entries

# Iteration:
iteritems - iterate over (key, value) pairs
iterkeys - iterate over key
itervalues - iterate over values
```
