class Solution {
public:
    int dp[38] = {0, };
    
    void init() {
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 0; i <= 34; ++i) {
            dp[i + 3] = dp[i] + dp[i + 1] + dp[i + 2];
        }
    }
    
    int tribonacci(int n) {
        init();
        return dp[n];
    }
};
