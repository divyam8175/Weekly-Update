class Solution {
public:
int solve(vector<int>&stones,int i,int sum,vector<vector<int>>&dp) {
    if(i>=stones.size()) {
        if(sum<0) return 1e9;
        return 0;
    }
    if(dp[i][sum+3000] != -1) return dp[i][sum+3000];
    int sum1=stones[i]+solve(stones,i+1,sum+stones[i],dp);
    int sum2=-stones[i]+solve(stones,i+1,sum-stones[i],dp);

    return dp[i][sum+3000]=min(sum1,sum2);
}
    int lastStoneWeightII(vector<int>& stones) {
        vector<vector<int>>dp(31,vector<int>(6000,-1));
        return solve(stones,0,0,dp);
    }
};