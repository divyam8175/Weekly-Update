class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w,
              vector<vector<int>>& vis, int i, int j) {
        int ans = 0;
        for (int k = i+1; k < m; k++) {
            if (vis[k][j] == 0 || vis[k][j] == -2) {
                if (vis[k][j] == 0)
                    ans = ans + 1;
                vis[k][j] = -2;
            } else {
                break;
            }
        }
        for (int k = i-1; k >= 0; k--) {
            if (vis[k][j] == 0 || vis[k][j] == -2) {
                if (vis[k][j] == 0)
                    ans = ans + 1;
                vis[k][j] = -2;
            } else {
                break;
            }
        }
        for (int k = j+1; k < n; k++) {
            if (vis[i][k] == 0 || vis[i][k] == -2) {
                if (vis[i][k] == 0)
                    ans = ans + 1;
                vis[i][k] = -2;
            } else {
                break;
            }
        }
        for (int k = j-1; k >=0 ; k--) {
            if (vis[i][k] == 0 || vis[i][k] == -2) {
                if (vis[i][k] == 0)
                    ans = ans + 1;
                vis[i][k] = -2;
            } else {
                break;
            }
        }
        return ans;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& g,
                       vector<vector<int>>& w) {
        int ans = 0;
        int count = m * n;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < w.size(); i++) {
            vis[w[i][0]][w[i][1]] = -1;
        }
        for (int i = 0; i < g.size(); i++) {
            vis[g[i][0]][g[i][1]] = -1;
        }
        for (int i = 0; i < g.size(); i++) {
            ans = ans + solve(m, n, g, w, vis, g[i][0], g[i][1]) + 1;
        }
        ans = ans + w.size();
        return count - ans;
    }
};