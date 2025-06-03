class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int no1=-1;
        int no2=-1;



        for(int i=0;i<tops.size();i++) {
            if(tops[i] != bottoms[i]) {
                no1=tops[i];
                no2=bottoms[i];
                break;
            }
        }
        if(no1==no2) return 0;
        bool flag=true;
        int count1=0;
        for(int j=0;j<tops.size();j++) {
            if(tops[j] != no1) {
                if(bottoms[j] != no1) {
                    flag=false;
                    count1=INT_MAX;
                    break;
                }else {
                    count1++;
                }
            }
        }
        flag=true;
        int count2=0;
        for(int j=0;j<tops.size();j++) {
            if(tops[j] != no2) {
                if(bottoms[j] != no2) {
                    flag=false;
                    count2=INT_MAX;
                    break;
                }else {
                    count2++;
                }
            }
        }
        flag=true;
        int count3=0;
        for(int j=0;j<tops.size();j++) {
            if(bottoms[j] != no1) {
                if(tops[j] != no1) {
                    flag=false;
                    count3=INT_MAX;
                    break;
                }else{
                    count3++;
                }
            }
        }
        flag=true;
        int count4=0;
        for(int j=0;j<tops.size();j++) {
            if(bottoms[j] != no2) {
                if(tops[j] != no2) {
                    flag=false;
                    count4=INT_MAX;
                    break;
                }else {
                    count4++;
                }
            }
        }
        int result=min({count1,count2,count3,count4});
        return result == INT_MAX ? -1 : result;
    }
};