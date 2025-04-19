class Solution {
public:
    int lowerbound(vector<int>& nums, int i, int lower, int upper) {
        int l = i + 1;
        int h = nums.size() - 1;
        int m = (l + h) / 2;
        while (l <= h) {
            if(nums[m]+nums[i]>=lower) {
                h=m-1;
            }else {
                l=m+1;
            }
            m = (l + h) / 2;
        }
        // cout<<l<<" "<<h<<endl<<endl;
        return l;
    }
    int upperbound(vector<int>& nums, int i, int lower, int upper) {
        int l = i + 1;
        int h = nums.size() - 1;
        int m = (l + h) / 2;
        while (l <= h) {
            if(nums[m]+nums[i]<=upper) {
                l=m+1;
            }else {
                h=m-1;
            }
            m = (l + h) / 2;
        }
        // cout<<l<<" "<<h<<endl<<endl;
        return h;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = lowerbound(nums, i, lower, upper);
            int h = upperbound(nums, i, lower, upper);
            if(h>=l)
            count = count + (h - l+1);
        }
        return count;
    }
};