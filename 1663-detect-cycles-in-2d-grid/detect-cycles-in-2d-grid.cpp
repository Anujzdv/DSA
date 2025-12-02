class Solution {
public:
     int n, m;
    vector<vector<int>> vis;

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        vis[x][y] = 1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(grid[nx][ny] != grid[x][y]) continue;

            if(vis[nx][ny]) {
                if(nx != px || ny != py) return true;
            }
            else {
                
                if(dfs(nx, ny, x, y, grid)) return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1, grid)) return true;
                }
            }
        }
        return false;
    }
};