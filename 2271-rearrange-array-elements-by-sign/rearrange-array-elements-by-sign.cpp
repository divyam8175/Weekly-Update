class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>neg;
        vector<int>pos;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] >= 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        int i=0;
        int j=0;
        bool flag=true;
        for(int k=0;k<nums.size();k++) {
            if(flag) {
                nums[k]=pos[i++];
            }else {
                nums[k]=neg[j++];
            }
            flag=!flag;
        }
        return nums;
    }
};