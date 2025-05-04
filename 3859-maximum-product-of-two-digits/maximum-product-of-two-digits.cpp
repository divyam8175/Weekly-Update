class Solution {
public:
    int maxProduct(int n) {
        vector<int>mpp;
        while(n>0) {
            mpp.push_back(n%10);
            n=n/10;
        }
        sort(mpp.begin(),mpp.end());
        return mpp[mpp.size()-1]*mpp[mpp.size()-2];
    }
};