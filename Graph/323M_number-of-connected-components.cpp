class Solution {
public:
    int parent[2001];
    void init() {
        for (int i = 0; i <= 2000; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void _union(int an1, int an2, int n) { // 개선필요
        if (an1 < an2) {
            for (int i = 0; i < n; ++i) {
                if (parent[i] == an2) parent[i] = an1;
            } 
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (parent[i] == an1) parent[i] = an2;
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        init();
        
        for (vector<int> v : edges) {
            int n1 = v[0];
            int n2 = v[1];
            
            int an1 = find(n1);
            int an2 = find(n2);
            
            if (an1 == an2) continue;
            
            _union(an1, an2, n);
        }
        
        
        
        
        
        unordered_map<int, int> m;
        
        for (int i = 0; i < n; ++i) { 
            if (m.find(parent[i]) == m.end()) {
                m.insert({parent[i], 1});
            }
        }
        
        return m.size();
    }
};
