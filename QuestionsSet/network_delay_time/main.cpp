class NodeData {
public:    
    bool visited;
    vector<pair<int, int>> adjlist;
};

bool myfunction (pair<int,int> i,pair<int,int> j) { return (i.second < j.second ); }

class Solution {
    map<int, NodeData> node;
    int cnt=0;    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {        
        //Build a graph data structure
        for(auto& item : times) {
            //cout << endl << item[0] << item [1] << item[2];
            auto ret = node.find(item[0]);
            if (ret == node.end()) {
                NodeData n;
                n.visited = false;
                n.adjlist.emplace_back(pair<int, int>(item[1], item[2]));
                node[item[0]] = n;
            } else {
                ret->second.adjlist.emplace_back(pair<int, int>(item[1], item[2]));
            }
        }
        /*
        cout << endl << "printing map:";        
        for (auto &item : node) {
            cout << endl << "[" << item.first << "] = ";
            for(auto &x : item.second.adjlist) {
                cout << x.first << " ";
            }
        }
        */
        int wt = mark_visited(K);
        if (cnt == N) {
            return wt;
        }
        return -1;
    }

    int mark_visited(int id) {
        node[id].visited = true;
        cnt++;
        int weight = 0;
        std::sort (node[id].adjlist.begin(), node[id].adjlist.end(), myfunction);
        for (auto &item : node[id].adjlist) {
            if(node[item.first].visited == false) {
                int tmp_weight = item.second;
                auto ret = node.find(item.first);
                if (ret != node.end()){
                    tmp_weight += mark_visited(item.first);
                }
                if (tmp_weight > weight)
                    weight = tmp_weight;
            }
        }
        return weight;
    }
        
};
