class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res(nums.size(),0);
        for(int i=0;i<queries.size();i++) {
            int start=queries[i][0];
            int end  =queries[i][1]+1;
            res[start]=res[start]-1;
            if(end<nums.size()) {
                res[end]=res[end]+1;
            }
        }
            cout<<res[0]<<endl;
        if(abs(res[0]) < nums[0]) return false;
        for(int i=1;i<nums.size();i++) {
            cout<<res[i]<<endl;
            res[i]=res[i]+res[i-1];
            if(abs(res[i]) < nums[i]) return false;
        }
        return true;
    }
};