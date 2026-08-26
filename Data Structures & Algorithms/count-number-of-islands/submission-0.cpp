class Solution {
public:
    int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0; k<4; k++)
        {
            int xx=i+x[k];
            int yy=j+y[k];
            if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]=='1' && !vis[xx][yy]) dfs(grid, vis, xx, yy);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans=0;
        for(int i=0; i<n ;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return ans;
    }
};
