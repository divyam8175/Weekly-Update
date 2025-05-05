class Solution {
public:
int solve(int n,vector<int>&dp) {
    if(n==1 || n==2) return n;
    if(n==3) return 5;
    if(dp[n] != -1) return dp[n];
    return dp[n]=((2*(solve(n-1,dp)%1000000007)%1000000007)+solve(n-3,dp)%1000000007)%1000000007;
}
    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};