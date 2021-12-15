class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[100001] = {0, };
        
        dp[0] = nums[0];
        int n = (int) nums.size();
        
        for (int i = 1; i < n; ++i) {
            int tmp = dp[i - 1] + nums[i];
            
            if (nums[i] > tmp) dp[i] = nums[i];
            else dp[i] = tmp;
        }
        int maximum_value = -100000;
        for (int i = 0; i< n; ++i) {
            if (maximum_value < dp[i]) {
                maximum_value = dp[i];
            }
        } return maximum_value;
    }
};

/* Short ver
class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        int n = (int) nums.size();
        int tmp = nums[0];
        int mv = tmp;
         
        for (int i = 1; i < n; ++i) { 
            tmp = (tmp < 0) ? nums[i] : tmp + nums[i];
            if (mv < tmp) mv = tmp;
        }
        
        return mv;
    }
};
*/
