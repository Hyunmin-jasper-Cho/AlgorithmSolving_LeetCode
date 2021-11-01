class Solution {
public:
    int xm[4] = {0, 0, -1, +1};
    int ym[4] = {-1, +1, 0, 0};
    
    int numIslands(vector<vector<char>>& grid) {
        bool vis[301][301] = {false, };
        
        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        
        for (int tx = 0; tx < n; ++tx) {
            for (int ty = 0; ty < m; ++ty) {
                if (vis[ty][tx] or (grid[ty][tx] == '0')) continue;
                
                vis[ty][tx] = true;
                queue<pair<int, int>> q; // x, y
                q.push({tx, ty}); // x, y

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; ++i) {
                        int nx = x + xm[i];
                        int ny = y + ym[i];

                        // in range
                        if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
                            if (vis[ny][nx]) continue;
                            
                            if (grid[ny][nx] == '1') {
                                q.push({nx, ny});
                                vis[ny][nx] = true;
                            }
                        }
                    }
                } num++;
            }
        } return num;
    }
};
