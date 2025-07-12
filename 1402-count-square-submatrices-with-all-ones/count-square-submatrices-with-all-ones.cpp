class Solution {
public:
int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&vis) {
    if(i>=matrix.size() || j>=matrix[0].size()) return 0;
    if(matrix[i][j] == 0) return 0;
    if(vis[i][j] != -1) return vis[i][j];
    int right=solve(matrix,i,j+1,vis);
    int diagnol=solve(matrix,i+1,j+1,vis);
    int bottom=solve(matrix,i+1,j,vis);

    return vis[i][j]=1+min({right,diagnol,bottom});

}
    int countSquares(vector<vector<int>>& matrix) {
        int result=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == 1)
                result+=solve(matrix,i,j,vis);
            }
        }
        return result;
    }
};