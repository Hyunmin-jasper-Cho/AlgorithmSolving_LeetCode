class Solution {
public:
    bool bs(vector<int>& mat, int target, int s, int e) {
        if (e >= s) {
            if (e == s) { // exception case
                if (mat[s] == target) return true;
                else return false;
            }
            
            int m = (e + s) / 2;
            if (mat[m] == target) return true;
            
            if (target < mat[m]) return bs(mat, target, s, m - 1);
            else return bs(mat, target, m + 1, e);
            
        } return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = (int) matrix.size();
        int w = (int) matrix[0].size();
        
        for (int i = h - 1; i >= 0; --i) {
            if (matrix[i][0] <= target) {
                // binary search
                if (!bs(matrix[i], target, 0, w - 1)) return false;
                return true;
            }
        }
        return false;
    }
};

