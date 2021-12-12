class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = (int) nums.size();
        
        if (n <= 2) {
            if (n == 1) return nums[0];
            else return min(nums[0], nums[1]);
        }
        
        int s = 0;
        int m = n / 2;
        int e = n - 1;
        
        while (true) {
            //----Key part----//
            if (nums[m] > nums[m + 1]) return nums[m + 1];
            else if (nums[m] < nums[m - 1]) return nums[m];
            //----Terminate Condition----//
            
            
            
            // Case1: first is smallest -> NOT rotated array
            if (nums[s] < nums[e]) return nums[s];
             
            
            // Case2: inflect point is at right
            else if (nums[m] > nums[s]) {
                s = m;
                m = (s + e) / 2;
            }
            
            // Case 3: inflect point is at left
            else if (nums[m] < nums[s]) {
                e = m;
                m = (s + e) / 2;
            }
        }
    }
};
