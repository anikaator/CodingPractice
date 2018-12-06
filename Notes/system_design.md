### Steps:
1. Start defining use cases

  Some of the common use cases are:
  - Analytics
  - Authentication
  - API or UI
  - Debugging/Introspect
  - HA
  - Load Balancer
  
2. Ask for scope, agree o to it
3. Contraints
  - How many traffic/request



### Examples :
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

  * Shortening Url

  ```
  Use cases:

  1. Stortening the lenth
  2. redirection
  3. Analytics
  4. Debugging
  5. url expiry
  6. Authntication
  7. custom url
  8. UI and API
---
* Uber
```
   * Features:
     - Customer Driver mapping
    - Mapping on map
    
   * Trip Storage:
      1. Close DC
      2. Backup DC
   
   * Kafka should be used for real time logging
```
   
