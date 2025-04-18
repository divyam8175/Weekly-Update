class Solution {
public:
bool solve(string &s,int i,int j,vector<vector<int>>&dp) {
    if(i>=j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == s[j]) return dp[i][j]=solve(s,i+1,j-1,dp);

    return dp[i][j]=0;
}
    string longestPalindrome(string s) {
        int maxi=0;
        int index=0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<s.size();i++) {
            for(int j=i;j<s.size();j++) {
                if(solve(s,i,j,dp)) {
                    if(j-i+1 > maxi) {
                        maxi=j-i+1;
                        index=i;
                    } 
                }
            }
        }
        return s.substr(index,maxi);
    }
};