class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n,vector<int>(n,0));
        vector<int> a;
        int rmin = 0, cmin = 0, rmax =n-1, cmax =n-1;
        int k = 0, l = 0;
        int fill=1;
        while (rmin<=rmax&&cmin<=cmax) {
            for (int i = cmin; i <= cmax; i++) {
                m[rmin][i]=fill++;
            }
            rmin++;
            for (int i = rmin; i <= rmax; i++) {
                m[i][cmax]=fill++;
            }
            cmax--;
            if(rmin<=rmax){
                for (int i = cmax; i >= cmin; i--) {
                  m[rmax][i]=fill++;
                }
                rmax--;
            }
            if(cmin<=cmax){
                for (int i = rmax; i >= rmin; i--) {
                  m[i][cmin]=fill++;
                }
                cmin++;
            }
        }
        return m;
    }
};