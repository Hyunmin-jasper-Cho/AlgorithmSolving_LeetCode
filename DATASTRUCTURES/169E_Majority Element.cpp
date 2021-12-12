class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hm;
        
        for (int v : nums) {
            if(hm.find(v) == hm.end()) { // not exist
                hm.insert({v, 1});
            } else {
                hm.at(v) += 1; 
            }
        }
        
        int val = -1;
        int cnt = -1;
        for (auto & itr : hm) {
            // printf("%d->%d\n", itr.first, itr.second);
            if (cnt < itr.second) {
                cnt = itr.second;
                val = itr.first;
            }
        }
        
        return val;
    }
};
