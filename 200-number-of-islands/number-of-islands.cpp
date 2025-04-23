class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto itr = q.front();
                        q.pop();
                        grid[itr.first][itr.second] = '0';
                        for (int i = 0; i < 4; i++) {
                            int newx=x[i] + itr.first;
                            int newy=y[i] + itr.second;
                            if (newx >=0 && newx<grid.size() &&  newy>=0 && newy<grid[0].size() && grid[newx][newy] =='1') {
                                grid[newx][newy] = '0';
                                // cout<<newx<<" "<<newy<<endl;
                                q.push({x[i] + itr.first, y[i] + itr.second});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};