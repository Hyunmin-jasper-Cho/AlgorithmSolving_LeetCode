class Solution {
public:
    bool detectCapitalUse(string word) {
        int N = (int) word.length();
        if (N == 1) return true;
        
        bool is_first_letter_capital = false;
        int cnt = 0;
        
        if (word[0] <= 90) {
            is_first_letter_capital = true;
            cnt++;
        }
        
        for (int i = 1; i < N; ++i) {
            if (word[i] <= 90) {
                cnt++;
            }
        }
        
        if (cnt == N or (cnt == 1 and is_first_letter_capital) or cnt == 0) return true;
        return false;
    }
};


