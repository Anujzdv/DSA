class Solution {
public:
    int dfs(int r, int c,vector<vector<int>>& grid, vector<vector<int>> &vis){
        int row = grid.size();
        int col = grid[0].size();
        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0 || vis[r][c]){
            return 0;
        }
        vis[r][c] = 1;
        int area = 1;
        area += dfs(r-1,c,grid,vis);
        area += dfs(r+1,c,grid,vis);
        area += dfs(r,c-1,grid,vis);
        area += dfs(r,c+1,grid,vis);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis (m, vector<int>(n,0));
        int maxarea = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    // vis[i][j] = 1;
                    int area = dfs(i,j,grid,vis);
                    maxarea = max(maxarea,area);  
                }
            }
        }
        return maxarea;
    }
};