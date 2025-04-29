class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>>points{p1,p2,p3,p4};
        sort(points.begin(),points.end());
        int side1=abs(points[0][0]-points[1][0]) + abs(points[0][1]-points[1][1]);
        int side2=abs(points[0][0]-points[2][0]) + abs(points[0][1]-points[2][1]);
        int side3=abs(points[3][0]-points[1][0]) + abs(points[3][1]-points[1][1]);
        int side4=abs(points[3][0]-points[2][0]) + abs(points[3][1]-points[2][1]);


        int diag1=abs(points[1][0]-points[2][0]) + abs(points[1][1]-points[2][1]);
        int diag2=abs(points[3][0]-points[0][0]) + abs(points[3][1]-points[0][1]);

        if(side1==0 || side2==0 || side3==0 || side4==0 || diag1==0 || diag2==0) return false;
        if(side1 == side2 && side2 == side3 && side3 == side4 && side4 == side1) {
            if(diag1 == diag2) {
                return true;
            }
        }
        return false;
    }
};