class Solution {
public:
    int total_cost[100];
    
    int dynamic_programming(vector<int>& cost, int end) {
        total_cost[0] = cost[0];
        total_cost[1] = max(cost[0], cost[1]);
        
        for (int i = 2; i < end; ++i) {
            total_cost[i] = max(total_cost[i - 2] + cost[i], total_cost[i - 1]);
        }
        return total_cost[end - 1];
    }   
    
    
    int rob(vector<int>& nums) {
        int N = (int) nums.size();
        
        // Exception Case
        if (N == 1) return nums[0];
        else if (N == 2) return max(nums[0], nums[1]);
        
        
        // General Case
        return dynamic_programming(nums, N);
    }
};
