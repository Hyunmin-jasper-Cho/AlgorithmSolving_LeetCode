class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = -1;
        for (auto vec : accounts) {
            int tmp = 0;
            for (int val : vec) {
                tmp += val;
            } max_wealth = (max_wealth < tmp) ? tmp : max_wealth;
        } 
        return max_wealth;
    }
};
