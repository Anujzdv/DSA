class Solution {
public:
    void helper(int i, int j,vector<vector<char>>& grid, vector<vector<bool>>& vis, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1'){
            return;
        }
        vis[i][j]= true;
        helper(i-1,j,grid,vis,n,m);
        helper(i+1,j,grid,vis,n,m);
        helper(i,j-1,grid,vis,n,m);
        helper(i,j+1,grid,vis,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0; i< n; i++){
            for(int j = 0; j<m ;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                     helper(i,j,grid, vis, n, m);
                    island++;
                }
            }
        }
        return island;
    }
};