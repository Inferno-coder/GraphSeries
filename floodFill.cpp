class Solution {
    int dir[5]={0,1,0,-1,0};
    bool pos(int r,int c,vector<vector<int>>&mat){
        int totr=mat.size();
        int totc=mat[0].size();
        return r>=0 && r<totr && c>=0 && c<totc;
    }
    void dfs(int sr,int sc,vector<vector<bool>>&vis,vector<vector<int>>&mat,int initial,int newColor){
        if(vis[sr][sc]==true)return;
        vis[sr][sc]=false;
        for(int i=0;i<4;i++){
            if(pos(sr+dir[i],sc+dir[i+1],mat) && !vis[sr+dir[i]][sc+dir[i+1]] && mat[sr+dir[i]][sc+dir[i+1]]==initial){
            mat[sr+dir[i]][sc+dir[i+1]]=newColor;
            dfs(sr+dir[i],sc+dir[i+1],vis,mat,initial,newColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>>mat=image;
        if(mat[sr][sc]==newColor)return mat;
        int initial=mat[sr][sc];
        mat[sr][sc]=newColor;
        vector<vector<bool>>vis(image.size(),vector<bool>(image[0].size()));
        dfs(sr,sc,vis,mat,initial,newColor);
        return mat;
    }
};
