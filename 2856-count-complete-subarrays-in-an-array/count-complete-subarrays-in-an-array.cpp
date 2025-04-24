class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>mpp1;
        for(int i=0;i<nums.size();i++)mpp[nums[i]]++;
        int i=0;
        int j=0;
        int count=0;
        int n=nums.size();
        while(j<nums.size()){
            mpp1[nums[j]]++;
            if(mpp1.size() == mpp.size()) {
                count+=(n-j);
                while(i<=j && mpp1.size() == mpp.size()) {
                    mpp1[nums[i]]--;
                    if(mpp1[nums[i]] == 0) mpp1.erase(nums[i]);
                    if(mpp1.size() == mpp.size()) count+=(n-j);
                    i++;
                }
            }
            j++;
        }
        return count;
    }
};