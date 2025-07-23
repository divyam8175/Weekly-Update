class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix.resize(n);
        for (int i = 0; i < n; i++)
            prefix[i].resize(m);
        for (int i = 0; i < n; i++)
            prefix[i][0] = matrix[i][0];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if(j-1>=0)
                prefix[i][j] = prefix[i][j - 1] + matrix[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if(j-1>=0)
                prefix[j][i] += prefix[j - 1][i];
            }
        }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout<<prefix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1 = prefix[row2][col2];
        int sum2 = 0;
        if(row1-1>=0 && col1-1>=0 ) sum2=prefix[row1 - 1][col1 - 1];
        int sum3 = 0;
        if(row1-1>=0) sum3=prefix[row1 - 1][col2];
        int sum4 = 0;
        if(col1-1>=0) sum4=prefix[row2][col1 - 1];
        return sum1 - sum3 - (sum4 - sum2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */