class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> s_v = get_remain_char(s);
        vector<char> t_v = get_remain_char(t);
        
        if (s_v.size() != t_v.size()) return false;
        
        for (int i = 0; i < (int) s_v.size(); ++i) {
            if (s_v[i] != t_v[i]) return false;
        } return true;
    }
    
private:
    vector<char> get_remain_char(string s) {
        vector<char> v;
        
        int sl = (int) s.length();
        
        int sharp = 0;
        for (int i = sl - 1; i >= 0; --i) {
            if (s[i] == '#') {
                sharp++; continue;
            }
            
            if (sharp != 0) {
                sharp--; continue;
            }
            
            v.emplace_back(s[i]);
        }
        
        return v;
    }
};
