class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int N = intervals.size();
         
        int idx = 0;
        
        sort(intervals.begin(), intervals.end()); 
        
        
        
        int ns = -1, ne = -1;
        for (int i = 0; i < N - 1; ++i) {
            
            if (intervals[i][1] >= intervals[i + 1][0] or ne >= intervals[i + 1][0]) { // overlapping case
                int tmp_e = max(intervals[i][1], intervals[i + 1][1]);
                ne = ne > tmp_e ? ne : tmp_e;
                
                if (ns == -1) {
                    ns = intervals[i][0]; // 시작부분 정의
                }  
            } else { // non overlapping
                if (ns == -1) { // 새로이 겹쳤던 부분이 없다면
                    insert(intervals[i][0], intervals[i][1]); 
                    idx++;
                } else { // 겹쳤던 부분이 있었다면..
                    int tmp_e = max(intervals[i][1], intervals[i - 1][1]);
                    ne = ne > tmp_e ? ne : tmp_e; 
                    
                    insert(ns, ne);  
                    idx++;
                    
                    ns = -1;
                    ne = -1;
                }
            }
        } 
        
        if (ns != -1) {
            int tmp_e = max(intervals[N - 1][1], intervals[N - 2][1]);
            ne = ne > tmp_e ? ne : tmp_e; 
            insert(ns, ne);
        } else insert(intervals[N - 1][0], intervals[N - 1][1]);
         
        return ans;
    }
    
private:
    void insert(int s, int e) {
        vector<int> a;
        a.emplace_back(s);
        a.emplace_back(e);
        
        ans.emplace_back(a);
    }
};
