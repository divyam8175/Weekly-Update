class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int size = isConnected.size();
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j])
                    mpp[i].push_back(j);
            }
        }
        int count = 0;
        vector<int> vis(size, 0);
        for (int i = 0; i < isConnected.size(); i++) {
            if (vis[i] == 1) continue;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto it : mpp[u]) {
                    if (vis[it] == 0) {
                        vis[it] = 1;
                        if(mpp[it].size())
                        q.push(it);
                    }
                }
            }
            count++;
        }
        return count;
    }
};