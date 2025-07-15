class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int result=-1;
        for(int i=0;i<nums.size();i++) {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k) {
                int sum=abs(target-(nums[i]+nums[j]+nums[k]));
                if(sum < ans) {
                    cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                    result=nums[i]+nums[j]+nums[k];
                    ans=sum;
                }
                if(nums[i]+nums[j]+nums[k] <= target) {
                    j++;
                }else {
                    k--;
                }
            }
        }
        return result;
    }
};