class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = (int) arr.size(); 
        if (n < 3) return false;
        
        int i = 0;
        while (i < n - 1 and arr[i] < arr[i + 1]) {
            i++;
        } 

        if (i == 0) return false;
        else if (i == n - 2) {
            if (arr[i] > arr[i + 1]) return true;
            else return false;
        }

        while (i < n - 1 and arr[i] > arr[i + 1]) {
            i++;
        }
        
        if (i != n - 1) return false;
        
        if (arr[i - 1] > arr[i]) return true;
        return false;
        
    }
};
