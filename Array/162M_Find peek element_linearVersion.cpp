class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = (int) nums.size();
        
        // exception
        if (n == 1) return 0;
        
        // last index
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        
        
        // general case: When ascending is stopped, then it is the answer. 
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) return i;
        }
        return -1;
    }
};
