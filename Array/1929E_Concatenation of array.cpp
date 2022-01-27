class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int N = (int) nums.size();
        
        for (int i = 0; i < N; ++i) {
            ans.emplace_back(nums[i]);
        }
        
        for (int i = 0; i < N; ++i) {
            ans.emplace_back(nums[i]);
        }
        
        return ans;
    }
};
