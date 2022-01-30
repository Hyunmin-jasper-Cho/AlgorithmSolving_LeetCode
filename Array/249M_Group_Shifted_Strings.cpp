class Solution { // O(650'000)
public:
    unordered_map<string, bool> hm[501];
    vector<string> v[501];
    int idx = 0;
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        
        // 우선 총 string 이 몇개 들어오는 지 구한다. (최대 500개)
        int N = (int) strings.size();
        
        
        // 우선 첫번째 string 은 hash map, vector 에 만들어 넣는다.
        add_sequence(strings[0], 0); // 최대 26회
        v[0].push_back(strings[0]);
        
        // 남은 string 들을 순회하면서... (최대 500회)
        for (int i = 1; i < N; ++i) {
            
            bool is_exist = false;
            // 현재 sequence 중 속하는 그룹이 있는지 확인한다.(최대 i - 1 번)
            for (int j = 0; j <= idx; ++j) {
                
                // 존재한다면..
                if (hm[j].find(strings[i]) != hm[j].end()) { // O(1)
                    
                    // 해당하는 sequence 의 vector 에 넣는다.
                    v[j].push_back(strings[i]);
                    is_exist = true;
                    break;
                }
                
            } if (!is_exist) { // 존재하지 않는다면.. -> 새로운 sequence 만들어야 함.
                // 우선 idx 늘려주고..
                idx++;
                
                // 해당 번째 idx 에 새로운 sequence map 생성
                add_sequence(strings[i], idx); // O(1300)
                v[idx].push_back(strings[i]);
            }
            
        }
        
        // 사용한 vector 들 전부 합침.
        for (int i = 0; i <= idx; ++i) {
            ans.push_back(v[i]);
        }
        
        return ans;
    }
    
private:
    // a: 97, z: 122
    void add_sequence(string& ori, int seq_num) { // 최대 1300회
        hm[seq_num].insert({ori, true});
        
        int len = (int) ori.length();
        string temp = ori;
        for (int i = 0; i < 26; ++i) { // 26회
            
            // 문자열의 모든 문자에 대해서 +1
            for (int j = 0; j < len; ++j) { // 최대 50
                // shift.. (z 보다 커지면 a 로 재할당 )
                temp[j] = (temp[j] + 1 > 122) ? 97 : temp[j] + 1;
            }
            
            hm[seq_num].insert({temp, true});
        }
    }
};
