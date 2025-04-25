class Solution {
public:
int dx[8]={-2, -1,  1, 2, 2, 1, -1,  -2};
int dy[8]={-1, -2, -2,-1, 1, 2,  2,   1};
double solve(int n,int k, int row, int col,vector<vector<vector<double>>> &dp) {
    if(row < 0 ||  row >= n || col >= n || col < 0) return 0;
    if(k==0) {
    //    if(row >= 0 && row < n && col < n && col >= 0) return 1;
       return 1;
    }

    if(dp[k][row][col] != -1) return dp[k][row][col];

    double a=solve(n,k-1,row+dx[0] ,col+dy[0],dp);
    double b=solve(n,k-1,row+dx[1] ,col+dy[1],dp);
    double c=solve(n,k-1,row+dx[2] ,col+dy[2],dp);
    double d=solve(n,k-1,row+dx[3] ,col+dy[3],dp);
    double e=solve(n,k-1,row+dx[4] ,col+dy[4],dp);
    double f=solve(n,k-1,row+dx[5] ,col+dy[5],dp);
    double g=solve(n,k-1,row+dx[6] ,col+dy[6],dp);
    double h=solve(n,k-1,row+dx[7] ,col+dy[7],dp);


    return dp[k][row][col]=((double)(a+b+c+d+e+f+g+h)/8);
}
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n, vector<double>(n, -1.0))
);

        return solve(n,k,row,col,dp);
    }
};