class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(k==0) return nums.size();
        int i=0;
        int j=1;
        int count=0;
        while(j<nums.size()) {
            while(j<nums.size() && nums[i] == nums[j]) {
                j++;
            }
            if(nums.size()-j >= k) {
                count+=(j-i);
            }
            i=j;
            j++;
        }
        return count;
    }
};