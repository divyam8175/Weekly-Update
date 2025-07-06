class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        priority_queue<pair<long long, pair<int, pair<int, int>>>,
                       vector<pair<long long, pair<int, pair<int, int>>>>,
                       greater<pair<long long, pair<int, pair<int, int>>>>>
            pq;
        pq.push({1, {1, {0, 0}}});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        while (!pq.empty()) {
            long long cost = pq.top().first;
            int time = pq.top().second.first;
            int x = pq.top().second.second.first;
            int y = pq.top().second.second.second;
            pq.pop();
            vis[x][y] = true;
            if (x == m - 1 && y == n - 1) {
                return cost;
            }
            if (time % 2 == 0) {
                pq.push({cost + waitCost[x][y], {time + 1, {x, y}}});
            } else {
                int dirx[2] = {0, 1};
                int diry[2] = {1, 0};
                for (int j = 0; j < 2; j++) {
                    int newx = x + dirx[j];
                    int newy = y + diry[j];
                    long long newcost = cost + (newx + 1) * (newy + 1);
                    if (newx >= 0 && newx < m && newy >= 0 && newy < n &&
                        vis[newx][newy] == false){
                        vis[newx][newy]=true;
                        pq.push({newcost, {time + 1, {newx, newy}}});
                        }
                }
            }
        }
        return 0;
    }
};