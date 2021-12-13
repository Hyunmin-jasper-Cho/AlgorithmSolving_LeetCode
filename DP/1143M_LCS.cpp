class Solution {
public:
    int m[1001][1001] = {0, };
    
    int longestCommonSubsequence(string text1, string text2) {
        int tl1 = (int) text1.length();
        int tl2 = (int) text2.length();
        
        init();
        
        for (int i = 1; i <= tl1; ++i) {
            for (int j = 1; j <= tl2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    m[i][j] = m[i - 1][j - 1] + 1;
                } else {
                    m[i][j] = max(m[i - 1][j], m[i][j - 1]);
                }
            }
        }
        
        return m[tl1][tl2];
    }
    
private:
    void init() {
        for (int i = 0; i <= 1000; ++i) {
            m[i][0] = 0;
            m[0][i] = 0;
        }
    }
};

