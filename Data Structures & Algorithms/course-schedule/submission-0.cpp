class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> adj[numCourses];
        for(auto i: prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0; 
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto i: adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        return count==numCourses;
    }
};
