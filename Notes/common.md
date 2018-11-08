- for checking and return dont use separate if statement. 

    return left > right;

- for finding top or first k element. Check to see if you can use priority queue. 
  Priority queue:
```cpp
//1st way:
priority_queue<int> q;
q.push(88);
q.top();
q.pop();

//2nd way(with own lambda funtion):

priority_queue<pair<string,int>, vector<pair<string,int>, Comp> Q;

      struct Comp {
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
            if (lhs.first > rhs.first)
              return true;
        }
        
```


- Adding values in hash for counting
```cpp
    unordered_map<string, int> my_map;
        for (auto& w : words)
            ++my_map[w];
```

