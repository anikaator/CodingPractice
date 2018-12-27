class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int size = ages.size();
        vector<int> year(121, 0);
        for (auto &x : ages) {
            year[x]++;
        }
        int count = 0;
        for(int i = 0; i < 121; i++) {
            for(int j = 0; j < 121; j++) {                              
                if (j > i){
                    continue;
                }                    
                if (j > 100 && i < 100){
                    continue;
                }                    
                if(j <= (0.5 * i) + 7) {
                      continue;  
                }
                count += (year[i] * year[j]);
                if (i == j)
                    count -= year[i];
            }
        }
        
        return count;
    }
};
