/*
  Search inflection value first, 
  then do binary search of each side
*/

class Solution {
public:
    int search(vector<int>& nums, int target) { 
        
        int n = (int) nums.size();
        
        if (n <= 2) {
            for (int i = 0; i < n; ++i) {
                if (nums[i] == target) return i;
            }
            return -1;
        }
        
        
        int s = 0;
        int m = n / 2;
        int e = n - 1;
        
        int inf_idx = -1;
        
        // Find inflection value's index first
        while (true) {
            
            // Terminate condition
            if (nums[m + 1] < nums[m]) {  
                inf_idx = m + 1; break;
            } else if (nums[m] < nums[m - 1]) {
                inf_idx = m; break;
            }
            
            // Not rotated.. just binary search
            if (nums[s] < nums[e]) {
                return bs(nums, target, s, e);
            }
            
            // Case 1: inf value is at right side
            if (nums[s] < nums[m]) {
                s = m;
                m = (s + e) / 2;
            } 
            // Case 2: inf value is at left side
            else {
                e = m;
                m = (s + e) / 2;
            }
        }
        
        int ls = bs(nums, target, 0, inf_idx - 1);
        int rs = bs(nums, target, inf_idx, n - 1);
        
        if (ls == rs) return -1;
        return (ls > rs) ? ls : rs;
    }
    
private:
    int bs(vector<int>& v, int target, int sta, int end) {
        
        if (end >= sta) {
            
            // exception
            if (end == sta) {
                return (v[sta] == target) ? sta : -1; 
            }
            
             
            int m = (sta + end) / 2;
            
            if (v[m] == target) return m;

            if (v[m] < target) { // search right 
                return bs(v, target, m + 1, end);
            } else {
                return bs(v, target, sta, m - 1);
            }
            
        } return -1;
        
    }
};
