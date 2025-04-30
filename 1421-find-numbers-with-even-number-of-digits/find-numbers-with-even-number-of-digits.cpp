class Solution {
public:
    int findNumbers(vector<int>& nums) {
        map<int,int>mpp;
        mpp[9]=1;
        mpp[99]=2;
        mpp[999]=3;
        mpp[9999]=4;
        mpp[99999]=5;
        mpp[999999]=6;
        mpp[9999999]=7;

        int count=0;
        for(int i=0;i<nums.size();i++) {
            for(auto itr:mpp) {
                if(nums[i] <= itr.first) {
                    if(itr.second%2==0) count++;
                    break;
                }
            }
        }
        return count;
    }
};