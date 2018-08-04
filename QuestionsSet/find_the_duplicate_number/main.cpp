class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int tort = nums[0];
        int hare = nums[0];
        do {
            tort = nums[tort];
            hare = nums[nums[hare]];
        }while( nums[hare] != nums[tort]);
        
        // Find the "entrance" to the cycle.
        int ptr1 = nums[0];
        int ptr2 = tort;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;        
    }
};
