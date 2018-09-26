class Solution {
public:
    int calculate(int i, vector<int>& nums) {
        int odd = 0, even = 0;
        if ((i + 2) < nums.size())
            odd = calculate(i+2, nums);
        if ((i + 3) < nums.size())
            even = calculate(i+3, nums);
        return (odd >= even) ? odd + nums[i] : even + nums[i] ;
    }    
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];        

        int oddsum = calculate(0, nums);
        int evensum = calculate(1, nums);
        return (oddsum > evensum) ? (oddsum):(evensum);
    }

};
