class Solution {
public:
    int parent[201];
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        
        int n = isConnected.size();
        init(n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (isConnected[i][j] == 0) continue;
                

                int ai = find_(i);
                int aj = find_(j);
                if (ai == aj) continue;

                
                if (ai < aj) parent[aj] = ai;
                else parent[ai] = aj;
            }
        }
        for (int i = 0; i < n; ++i) {
            int px = find_(parent[i]);
            if (parent[i] != px) parent[i] = px;
        }
        
        sort(parent, parent + n);
        
        for (int i = 0; i < n - 1; ++i) {
            if (parent[i] != parent[i + 1]) cnt++;
        }
        return cnt + 1;
    }
    
private:
    void init(int n) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    
    int find_(int x) {
        if (x == parent[x]) return x;
        
        return parent[x] = find_(parent[x]);
    } 
};
