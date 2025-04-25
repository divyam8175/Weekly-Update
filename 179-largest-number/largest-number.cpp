class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto mycoomp=[](int &a,int &b){
            string s1=to_string(a);
            string s2=to_string(b);
            return (s1+s2) > (s2+s1);
        };

        sort(nums.begin(),nums.end(),mycoomp);

        if(nums[0] == 0) return "0";

        string res="";
        for(auto itr:nums) res+=to_string(itr);
        return res;
    }
};