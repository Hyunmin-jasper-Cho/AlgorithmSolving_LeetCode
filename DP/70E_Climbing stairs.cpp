class Solution {
public:
    
    int climbStairs(int n) {
        
        int tot[46] = {0, };
        tot[1] = 1;
        tot[2] = 2;
        
        for (int i = 3; i <= 45; ++i) {
            tot[i] = tot[i - 1] + tot[i - 2];
        }
        return tot[n];
    }
};
