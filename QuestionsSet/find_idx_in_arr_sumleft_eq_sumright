/* Improvement
- You can calculate whole sum and then from left start fresh adding and from right sub from whole sum if thats equal then true
- You can use cpp algorithm 
```
     int sum = std::accumulate(v.begin(), <- start
                               v.end(), <- end 
                               0); <- initialize
                               
another operation 
    std::string s = std::accumulate(std::next(v.begin()), v.end(),
                                    std::to_string(v[0]), // start with first element
                                    [](std::string a, int b) {
                                        return a + '-' + std::to_string(b);
             output: 1-2-3-4-5-6-7-8-9-10                           
```
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int size = nums.size();
        vector <int> asc_arr(size, 0);
        vector <int> dsc_arr(size, 0);
        int asum = 0;
        int dsum = 0;
        int idx = 99999;
        for (int i = 0; i < size ; i++) {
            asum += nums[i];
            asc_arr[i] = asum;
            dsum += nums[size - i -1];
            dsc_arr[size - i - 1] = dsum;
            if (i >= size/2) {
                if (asc_arr[i] == dsc_arr[i] && i < idx)
                    idx = i;
                if (asc_arr[size -1 -i] == dsc_arr[size -1 -i] && (size -1 -i) < idx)
                    idx = (size -1 -i);
            }
        }
        /*
        for (auto &x : asc_arr) {
            cout << " " << x;
        }
        cout << endl;
        for (auto &x : dsc_arr) {
            cout << " " << x;
        }
        */
        if (idx == 99999)
            return -1;
        return idx;        
    }
};
