class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;

        for (int i = 0;; ++i) {
            int target_num = target - nums[i];
            
            // i <-> it is pair
            auto it = imap.find(target_num);

            
            // if i's pair, the it is exist in map
            if (it != imap.end()) {
                // i: myself index
                // it->second: i's pair's index
                
                return vector<int> {i, it->second};
            }

            // i's pair is not exist, then push i and its index
            imap[nums[i]] = i;
        }
    }
};
