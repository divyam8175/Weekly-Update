class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        unordered_map<int,int>mpp;
        long long count=0;
        int i=0;
        int j=0;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        queue<int>q;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > maxK || nums[i] < minK) {
                q.push(i);
            }
        }
        q.push(nums.size());
        while(j<nums.size()) {
            mini=min(mini,nums[j]);
            maxi=max(maxi,nums[j]);
            if(nums[j] == minK || nums[j] == maxK) {
                mpp[nums[j]]++;
            }
            if(nums[j] < minK || nums[j] > maxK) {
                mpp.clear();
                mini=INT_MAX;
                maxi=INT_MIN;
                i=j+1;
                j++;
                continue;
            }
            if(mini == minK && maxi == maxK) {
                while(q.size()>0 && q.front() < j) {
                    q.pop();
                }
                int k=q.front();
                while(i<=j && mpp[mini] > 0 && mpp[maxi] >0){ 
                    count+=(k-j);
                    mpp[nums[i]]--;
                    if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                    i++; 
                }
            }
            // cout<<i <<" "<< j<<endl;
            j++;
            // cout<<i <<" "<< j<<endl;
        }
        return count;
    }
};