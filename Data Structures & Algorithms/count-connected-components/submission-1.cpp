class Solution {
public:
    void dfs(int n, vector<int> adj[n], int i, vector<int>& vis){
        vis[i]=1;
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(n, adj, it, vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
                        adj[i[1]].push_back(i[0]);

        }
        int ans=0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(n, adj, i, vis);
            }
        }
        return ans;
    }
};
