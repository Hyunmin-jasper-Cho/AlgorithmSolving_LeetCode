class Solution {
public:
    
    int dp[31] = {0, };
    
    void init() {
        dp[1] = 1;
        
        for (int i = 2; i <= 30; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    
    int fib(int n) {
        init();
        return dp[n];
    }
};
