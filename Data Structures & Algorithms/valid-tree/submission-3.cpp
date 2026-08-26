class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<int> adj[n];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int count =0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto i: adj[node]){
                if(!vis[i]){
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
        return count==n;
    }
};
