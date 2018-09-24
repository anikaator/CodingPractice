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


### OOP
1. Start with:
- Start asking 6W's : who what when why where how
- Start defining core objects like table, guest, server, party, order, meal, employee etc.
- Analyse relationship 
       * which which objects are memeber of which obj.
       * Any object inherits from other obj.
       * relation 1-1, 1-many or many-many.
- Investigate actions
    For example a Party walks into the Restaurant, and a Guest requestsa Table from the Host. The Host looks up the Reservation and, if it exists, assigns the Party to a Table.Otherwise, the Party is added to the end of the list. When a Party leaves, the Table is freed and assigned to a new Party in the list.
 

2. Design Pattern:
- Singleton Class : The Singleton pattern ensures that a class has only one instance and ensures access to the instance through the application.
- Factory Method : The Factory Method offers an interface for creating an instance of a class, with its subclasses deciding which class to instantiate.    









References:
Cracking coding interview book
