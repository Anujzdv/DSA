class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& b,int m,int n){
        if(r<0||c<0||r>=m||c>=n||b[r][c]!='O')return;
        b[r][c]='#';
        dfs(r+1,c,b,m,n);
        dfs(r-1,c,b,m,n);
        dfs(r,c+1,b,m,n);
        dfs(r,c-1,b,m,n);
    }
    void solve(vector<vector<char>>& b){
        int m=b.size(); if(!m)return; 
        int n=b[0].size();
        for(int i=0;i<m;i++){
            if(b[i][0]=='O')dfs(i,0,b,m,n);
            if(b[i][n-1]=='O')dfs(i,n-1,b,m,n);
        }
        for(int j=0;j<n;j++){
            if(b[0][j]=='O')dfs(0,j,b,m,n);
            if(b[m-1][j]=='O')dfs(m-1,j,b,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]=='O')b[i][j]='X';
                else if(b[i][j]=='#')b[i][j]='O';
            }
        }
    }
};
