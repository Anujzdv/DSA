class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>&vis, int sclr){
       int row = image.size();
       int col = image[0].size();
        if (sr < 0 || sr >= row || sc < 0 || sc >= col ||vis[sr][sc] || image[sr][sc] != sclr) {
            return;
        }

        image[sr][sc] = color;
        vis[sr][sc] = 1;
        helper(image,sr+1,sc,color,vis,sclr);
        helper(image,sr-1,sc,color,vis, sclr);
        helper(image,sr,sc+1,color,vis, sclr);
        helper(image,sr,sc-1,color,vis, sclr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        vector<vector<int>>vis(n, vector<int>(image[0].size(),0));
        int sclr = image[sr][sc];
        if(sclr == color){
            return image;
        }
        helper(image,sr,sc,color,vis,sclr);
        return image;
    }
};