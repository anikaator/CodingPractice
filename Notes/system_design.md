* Twitter :

```
Features:
  1. Tweeting
  2. Timeline
    - user
    - homepage
  3. Following user
  
+--------------+
| tweet        |
|    |send     |
+--------------+
     |
     v

 +-----------+
 |  LB fan out
 |           |
 +----+------+
      |
      v

  +----------+
  |  +---------+
  |  | +---------+
  |  | |     | | |
  |  | |Redis| | |
  +----------+ | |
     +---------+ |
       +---------+
  
```
