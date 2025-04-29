class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager,vector<int>& informTime) {
        unordered_map<int, vector<pair<int, int>>> mpp;
        queue<pair<int, int>> q;
        int total=0;
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) {
                // total=max(total,informTime[i]);
                q.push({i, informTime[i]});
            } else {
                mpp[manager[i]].push_back({i, informTime[i]});
            }
        }
        while(!q.empty()) {
            int n=q.size();
            int maxi=0;
            while(n--) {
                auto p=q.front();
                q.pop();
                int m=p.first;
                int time=p.second;
                total=max(total,time);
                for(auto itr:mpp[m]) {
                    q.push({itr.first,itr.second+time});
                }
            }
            // total+=maxi;
        }
        return total;
    }
};