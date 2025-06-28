class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int>p;
        for(int i=0;i<nums.size();i++) {
            p.push(nums[i]);
        }
        vector<int>ans;
        unordered_map<int,int>mpp;
        while(k--) {
            mpp[p.top()]++;
            p.pop();
        }
        for(int i=0;i<nums.size();i++) {
            if(mpp[nums[i]] > 0) {
                ans.push_back(nums[i]);
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
            }
        }
        return ans;
    }
};