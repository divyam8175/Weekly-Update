class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n-1;i++) {
            int black=0;
            int white=0;
            for(int j=0;j<m-1;j++) {
                if(grid[i][j] == 'B') {
                    black++;
                }
                if(grid[i][j] == 'W') {
                    white++;
                }
                if(grid[i][j+1] == 'B') {
                    black++;
                }
                if(grid[i][j+1] == 'W') {
                    white++;
                }
                if(grid[i+1][j] == 'B') {
                    black++;
                }
                if(grid[i+1][j] == 'W'){
                    white++;
                }
                if(grid[i+1][j+1] == 'B') {
                    black++;
                }
                if(grid[i+1][j+1] == 'W') {
                    white++;
                }
            cout<<black<<" "<<white<<endl;
            if(abs(black-white) == 2 || abs(black-white) == 4) return true;
            }
        }
        return false;
    }
};