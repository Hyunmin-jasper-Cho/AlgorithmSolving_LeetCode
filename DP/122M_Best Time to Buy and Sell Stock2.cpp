class Solution {
public:
    int maxProfit(vector<int>& cost) {
        int max_profit = 0;
        
        int n = (int) cost.size();
        for (int i = 0; i < n - 1; ++i) {
            if (cost[i + 1] > cost[i]) {
                max_profit += (cost[i + 1] - cost[i]);
            }
        }
        
        
        return max_profit;
    }
};

