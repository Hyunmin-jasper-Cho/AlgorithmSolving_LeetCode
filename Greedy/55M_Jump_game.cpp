// Greedy Solution.. O(N)
class Solution {
public:   
    bool canJump(vector<int>& nums) {
        int last_pos = (int) nums.size() - 1; 
        
        for (int i = last_pos - 1; i >= 0; --i) {
            if (i + nums[i] >= last_pos) {
                last_pos = i;
            }
        }
        return (last_pos == 0) ? true : false;
    }
};


/*: BackTrack Solution.. O(N^2)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vis[0] = true;
        return recur_solution(nums, 0);
    }
    
private: 
    bool vis[10002] = {false, };
    
    bool recur_solution(vector<int> &nums, int idx) {
        bool ans = false;
        
        // Terminate Condition
        vis[idx] = true;
        
        int N = (int) nums.size();
        if (N == 1) return true;
        if (idx == N - 1) return true;
        else if (idx >= N) return false; // // oveflow
        
        // General Case
        for (int i = 1; i <= nums[idx]; ++i) {
            if (vis[idx + i]) continue;
            
            bool tmp = recur_solution(nums, idx + i);
            if (tmp) return tmp;
        }
        return ans;
    }
};
*/
