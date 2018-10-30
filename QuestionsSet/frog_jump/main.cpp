class Solution {
public:
    
    bool findPath(int curr, int jump, set<int>& stone_set, set<pair<int, int>>& memo, int goal) {
        if (curr == goal)
            return true;
        auto it = stone_set.find(curr);
        if(jump < 0 || curr < 0 || it == stone_set.end())
            return false;          
        if (memo.find(pair<int, int>(curr, jump)) != memo.end())
            return false;       
        memo.insert(pair<int, int>(curr, jump));  
        for (int i = 1; i >= -1; i-- ) {
            if (findPath(curr + jump + i, jump + i, stone_set, memo, goal))
                return true;
        }
        return false;   
    }
    bool canCross(vector<int>& stones) {
        if(stones[0] != 0)
            return false;
        int goal = stones[stones.size() - 1];
        set<int> stone_set;    
        for (auto &x : stones) {
            stone_set.insert(x);
        }
        set<pair<int, int>> memo;
        return findPath(0, 0, stone_set, memo, goal);        
    }
};
