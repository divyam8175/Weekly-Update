class Solution {
public:
void solveleft(vector<int>&nums,vector<bool>&vis,vector<int>&ans,int i,int k) {
    for(int j=i;j>=0;j--) {
        if(abs(i-j) <= k && vis[j] == false) {
            ans.push_back(j);
            vis[j]=true;
        }
    }
}
void solveright(vector<int>&nums,vector<bool>&vis,vector<int>&ans,int i,int k) {
    for(int j=i;j<nums.size();j++) {
        if(abs(i-j) <= k && vis[j] == false) {
            ans.push_back(j);
            vis[j]=true;
        }
    }
}
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int>ans;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++) {
            if(nums[i] == key) {
                solveleft(nums,vis,ans,i,k);
                solveright(nums,vis,ans,i,k);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};