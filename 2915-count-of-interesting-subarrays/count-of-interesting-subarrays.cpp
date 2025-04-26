class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int,int>mpp;
        vector<int>prefix(nums.size(),0);
        for(int i=0;i<nums.size();i++) {
            if(nums[i] % modulo == k) {
                prefix[i]=1;
            }
        }
        long long sum=0;
        long long count=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++) {
            sum+=prefix[i];

            int rem=(sum-k)%modulo;


            count+=mpp[rem];

            mpp[sum%modulo]++;
        }
        return count;
    }
};