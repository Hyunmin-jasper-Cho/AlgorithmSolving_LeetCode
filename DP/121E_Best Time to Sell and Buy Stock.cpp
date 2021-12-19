class Solution {
public:
    int maxProfit(vector<int>& C) {
        int min_price = 10000001;
        int max_profit = 0;
        
        for (auto & itr : C) {
            if (itr < min_price) min_price = itr;
            else if (max_profit < itr - min_price) {
                max_profit = itr - min_price;
            }
        } 
        return max_profit;
    }
};

