class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi=*max_element(nums.begin(),nums.end());
        long long count=0;
        long long maxicount=0;
        int i=0;
        int  j=0;
        while(j<nums.size()) {
            if(nums[j] == maxi) maxicount++;
            while(i<=j && maxicount>=k) {
                count+=(nums.size()-j);
                if(nums[i] == maxi) maxicount--;
                i++;
            }
            j++;
        }
        return count;
    }
};