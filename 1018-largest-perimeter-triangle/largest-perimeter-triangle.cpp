class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=2;
        int area=0;
        while(i<nums.size()) {
            int a=nums[i];
            int b=nums[i-1];
            int c=nums[i-2];
            if((a+b) > c && b+c > a && a+c > b) {
                area=max(area,a+b+c);
            }
            i++;
        }
        return area;
    }
};