class Solution {
public:
int solve(string &s,int i,int j,vector<vector<int>>&dp) {
    if(i>j) return 0;
    if(i==j) return 1;
    int count=0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == s[j]) {
        count=max(count,2+solve(s,i+1,j-1,dp));
    }
    count=max(count,solve(s,i+1,j,dp));
    count=max(count,solve(s,i,j-1,dp));
    return dp[i][j]=count;
}
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        int n=solve(s,0,s.size()-1,dp);
        cout<<n;
        return s.size()-n;
    }
};