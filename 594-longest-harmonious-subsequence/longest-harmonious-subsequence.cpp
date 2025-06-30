class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int ans=0;
        while(j<n) {
            mini=min(mini,nums[j]);
            maxi=max(maxi,nums[j]);
            while(i< j && maxi-mini > 1) {
                i++;
                mini=nums[i];
            }
            if(mini != maxi)
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};