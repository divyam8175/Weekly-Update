class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        map<int,int>mpp;
        int total=nums.size();
        for(int i=0;i<nums.size();i++) {
            mpp[nums[i]]++;
        }
        int count=0;
        int size=0;
        for(auto itr:mpp) {
            size+=itr.second;
            if(total-size >= k) {
                count+=itr.second;
            }
        }
        return count;
    }
};