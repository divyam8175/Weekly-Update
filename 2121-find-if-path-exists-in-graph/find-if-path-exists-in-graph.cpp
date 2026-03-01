class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<edges.size();i++) {
            int u=edges[i][0];
            int v=edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        bool ans=false;
        queue<int>q;
        q.push(source);
        vector<int>vis(n,0);
        while(!q.empty()) {
            int u=q.front();
            q.pop();

            if(u==destination) {
                return true;
            }

            vis[u]=1;
            for(auto it:mpp[u]) {
                if(vis[it]==0) {
                    q.push(it);
                    vis[it]=1;
                }
            }
        } 
        return ans;
    }
};