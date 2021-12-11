class Solution {
public:
    
    // 's' and 'e' is ACCESSABLE INDEX OF ARRAY
    int bs(vector<int>& nums, int s, int e, int target) {
            if (e >= s) {
                if (e == s) { // exception case
                    if (nums[s] == target) return s;
                    else return -1;
                }
                
                int m = (s + e) / 2;
                
                if (nums[m] == target) return m;
                
                if (target < nums[m]) return bs(nums, s, m - 1, target);
                else if (target > nums[m]) return bs(nums, m + 1, e, target);
                
            } return -1;
        }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int idx = bs(nums, 0, (int) nums.size() - 1, target);
        int lm = idx, rm = idx;
        
        if (lm == -1) {
            ans.emplace_back(-1);
            ans.emplace_back(-1);
        } else {
            
            for (int i = idx - 1;;) {
                if (i < 0) break; // underflow
                
                if (nums[i] == target) {
                    lm = i;
                    i--;
                } else break;
            }
            
            for (int i = idx + 1;;) {
                if (i > (int) nums.size() - 1) break; // overflow
                
                if (nums[i] == target) {
                    rm = i;
                    i++;
                } else break;
            }
            ans.emplace_back(lm);
            ans.emplace_back(rm);
        }
        
        return ans;
    }
};



