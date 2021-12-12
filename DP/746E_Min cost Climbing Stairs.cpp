class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        if (n <= 3) {
            if (n == 2) {
                return min(cost[0], cost[1]);
            } return min(cost[1], cost[0] + cost[2]);
        } 
        
        /*
        시작은 index 0 에서하든, 1에서 하든 무관. 
        top_idx 에 도달해야 함. 
        
        F(n) = n 번째 계단까지 올라가는 데 가장 적은 비용
        F(n) = min(F(n - 1) + cost(n - 1), F(n - 2) + cost(n - 2)) 
        */
        
        int Fo[1000 + 1] = {0, };
        int Fz[1000 + 1] = {0, };
        
        int start_from_one_cost = 0;
        int start_from_zero_cost = 0;
        
        // start from one -> use from F1, (F1, F2)
        Fo[1] = 0; Fo[2] = cost[1];
        for (int i = 3; i <= n; ++i) {
            Fo[i] = min((Fo[i - 1] + cost[i - 1]), (Fo[i - 2] + cost[i - 2]));
        }
        start_from_one_cost = Fo[n];
        
        
        
        // start from zero -> use from F0, (F0, F1)
        Fz[0] = 0; Fz[1] = 0;
        for (int i = 2; i <= n; ++i) {
            Fz[i] = min((Fz[i - 1] + cost[i - 1]), (Fz[i - 2] + cost[i - 2]));
        }
        start_from_zero_cost = Fz[n];
        
        return min(start_from_zero_cost, start_from_one_cost);
    }
};
