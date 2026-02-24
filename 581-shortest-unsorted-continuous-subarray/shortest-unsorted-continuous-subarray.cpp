class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int start = nums.size() - 1;
        int end = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < maxi) {
                end = i;
            }
            maxi = max(maxi, nums[i]);

            if (nums[nums.size() - i - 1] > mini) {
                start = nums.size() - i - 1;
            }
            mini = min(mini, nums[nums.size() - i - 1]);
        }
        cout<<start<<" "<<end<<" "<<endl;
        return (end-start+1)<0?0:(end-start+1);
    }
};