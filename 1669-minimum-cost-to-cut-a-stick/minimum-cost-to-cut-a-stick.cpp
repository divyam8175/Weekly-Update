class Solution {
public:
    int solve(vector<int>& cuts, int i, int j,vector<vector<int>>&dp) {
        if (j-i < 2)   
            return 0;
        int result = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for (int k = i+1; k <= j-1; k++) {
            result=min(result,((cuts[j]-cuts[i])+solve(cuts,i,k,dp)+solve(cuts,k,j,dp)));
        }
        return dp[i][j]=result;
    }
    int minCost(int n, vector<int>& cuts) { 
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(cuts, 0, cuts.size()-1,dp); 
    }
};