class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>temp=nums;
        int sum=-1;
        int n=nums.size();
        sort(temp.begin(),temp.end());
        for(int i=0;i<nums.size();i++) {
            if(temp[i] != nums[i]) {
                if(sum==-1) {
                    sum=nums[i];
                }else {
                    sum=sum&nums[i];
                }
            }
        }
        return sum==-1?0:sum;
    }
};