class Solution {
public:
    int m[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
    
    //  1: 2147483648
    //  0: overflow
    // -1: can exporess as int
    int recur(int ans_arr[10], int depth) {
        if (depth == 10) return 1;
        
        if (ans_arr[depth] >= m[depth] + 1) return 0;
        
        if (ans_arr[depth] == m[depth]) { 
            return recur(ans_arr, depth + 1);
        }
        return -1;
    }
    
    
    int reverse(int x) {  
        if (x == 0 or x == -2147483648) return 0;
        
        int save_x = x;
        if (save_x < 0) save_x *= -1;
        
        int ans_arr[10] = {0, };
        int idx = 0;
        
        fill(ans_arr, ans_arr + 10, -1);
        
        while (true) {
            ans_arr[idx++] = save_x % 10; 
            save_x /= 10;
            
            if (save_x == 0) break;
        }
        
        if (idx == 10) {
            int b = recur(ans_arr, 0);
            if (b == 0 or (b == 1 and x > 0)) return 0;
        }
        
        int ans = 0;  
        for (int i = 0; i < idx; ++i) {
            ans = (ans * 10) + ans_arr[i];
        }
        
        if (x < 0) return -ans;
        return ans;
    }
};
