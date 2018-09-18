class Graph {
public:    
    map<string, multiset<string>> table;    
};

class Solution {    
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        Graph graph;
        for(auto &x : tickets) {
            auto it = graph.table.find(x.first);
            if (it == graph.table.end()) {
                multiset<string> adjlist {x.second};
                graph.table[x.first] = adjlist;    
            } else {
                it->second.insert(x.second);
            }            
        }
        /*
        cout << "\nPrint paths :";
        for(auto &x : graph.table) {
            cout << endl << x.first << " : ";
            for (auto &y : x.second) {
                cout << y << " ";
            }
        }
        */
        vector<string> ret;
        string curr = "JFK";
        auto ptr = graph.table.find(curr);
        while( ptr != graph.table.end()) {
            ret.emplace_back(curr);
            cout << endl << "Added :" << curr;
            auto found = (ptr->second.begin());            
            if (found == ptr->second.end())
                break;            
            cout << endl << "Found :" << *found; 
            while (graph.table.find(*found) == graph.table.end() && next(found, 1) != ptr->second.end()) {
                found++;                
            }
            curr = *found;
            ptr->second.erase(found);
            ptr = graph.table.find(curr);
            if (ptr == graph.table.end()) {
                ret.emplace_back(curr);
            }
        }       
        return ret;
    }
};
