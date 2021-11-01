class Solution {
public:
    bool vis[51][51] = {false, };
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(); // 세로줄
        int n = grid[0].size(); // 가로줄
        
        vector<pair<int, int>> v;
        for (int i = 0; i < m; ++i) { // i for y
            for (int j = 0; j < n; ++j) { // j for x
                if (grid[i][j] == 1) {
                    v.emplace_back(make_pair(j, i)); // x and y 
                }
            }
        }
        
        int ans = 0;
        for (auto & itr : v) {
            int x = itr.first;
            int y = itr.second;
            
            int tmp = bfs(x, y, m, n, grid);
            ans = ans < tmp ? tmp : ans;
        }
        return ans;
    }
    
private:
    int xm[4] = {0, 0, -1, 1};
    int ym[4] = {-1, 1, 0, 0};
    
    int bfs(int x, int y, int m, int n, vector<vector<int>>& grid) {
        if (vis[y][x]) return -1;
        
        int ans = 0;
        
        vis[y][x] = true; ans++;
        queue<pair<int, int>> q; // x, y;
        
        
        q.push({x, y});
        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nx = cx + xm[i];
                int ny = cy + ym[i];
                
                if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
                    if (!vis[ny][nx] and grid[ny][nx] == 1) {
                        ans++;
                        vis[ny][nx] = true;
                        q.push({nx, ny});
                    }
                }
            }
        } return ans;
    }    
};
