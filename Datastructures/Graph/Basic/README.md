Graphs differnt types:
- If there is path between every vertices its called connected graphs.
- If there are no cycles then its called acyclic graph.
- Edges can have uni directional or bi directional edges.

Graph data structures:
```c++ 
class Graph {
  public Node[] nodes;
}

class Node {
  public string name;
  public Node[] children;
}
```

* You can also maintain vector or arraylist as a adjacency list.
* Or you can represent adjacency matrices to represent above, but vector would be more efficient.

Graph search :
- Depth first search
  * DFS is often preferred if we want to visit every node in the graph. Both will work just fine, but depth-first search is a bit simpler. 
  * Its somewhat similar to pre-order recursive
- Breath first search
  * If we want to find the shortest path (or just any path) between two nodes, BFS is generally better.
  * You have to use queue and not recursive.
  * Add root in queue and mark it as visited and then itertated through queue its it not empty and keep adding adjacent nodes.
  
  
* Bidirectional search is used to find the shortest path between a source and destination node. It operates by essentially running two simultaneous breadth-first searches, one from each node. When their searches collide, we have found a path.


