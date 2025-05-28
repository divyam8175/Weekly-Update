class Solution {
public:
bool find(vector<int>&nums,int i) {
    int l=0;
    int h=nums.size()-1;
    int m=(l+h)/2;
    while(l<=h) {
        if(nums[m] == i) return false;
        else if(nums[m] < i) {
            l=m+1;
        }else {
            h=m-1;
        }
        m=(l+h)/2;
    }
    return true;
}
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<pow(2,31);i++) {
            if(find(nums,i)) {
                return i;
            }
        }
        return -1;
    }
};