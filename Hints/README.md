### Tree:
1. To check of subtree remember node with differnt combination will also produce same result.
```
    3                          4
      \           and        /
        4                  3
INORDER : 3 4  and 3 4        
```
the way you can solve is you can fill out NULL nodes with string NULL so now you can compare in one of the traversal
```
    3                          4
  /   \           and        /   \
 NULL   4                  3      NULL
 INORDER : 3 NULL 4 and 4 3 NULL 
```
