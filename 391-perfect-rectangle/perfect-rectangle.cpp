class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>mpp;
        for(auto itr:rectangles) {
            int x1=itr[0];
            int y1=itr[1];
            int a1=itr[2];
            int b1=itr[3];
            mpp[{x1,y1}]++;
            mpp[{a1,b1}]++;
            mpp[{x1,b1}]--;
            mpp[{a1,y1}]--;
        }
        map<int,int>adj;
        int count=0;
        for(auto itr:mpp) {
            if(itr.second != 0) {
                if(abs(itr.second) != 1) return false;
                count++;
            }
        }
        return count==4;
    }
};