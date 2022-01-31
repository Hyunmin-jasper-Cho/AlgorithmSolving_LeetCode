class Solution {
public:
    void rotate(vector<int>& nums, int K) {
        // shift 된 시작지점: N - (K % N), N: nums.size()
        vector<int> tmp;
        
        int N = (int) nums.size();
        int shift_sta = N - (K % N);
        for (int i = shift_sta; i < N; ++i) {
            tmp.push_back(nums[i]);
        }
        for (int i = 0; i < shift_sta; ++i) {
            tmp.push_back(nums[i]);
        }
        
        for (int i = 0; i < N; ++i) {
            nums[i] = tmp[i];
        }
    }
};
