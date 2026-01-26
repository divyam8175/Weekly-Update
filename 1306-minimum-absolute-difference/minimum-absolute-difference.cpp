class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        map<int,vector<vector<int>>>mpp;
        for(int i=0;i<arr.size()-1;i++) {
            mpp[arr[i+1]-arr[i]].push_back({arr[i],arr[i+1]});
            mini=min(mini,arr[i+1]-arr[i]);
        }
        return mpp[mini];
    }
};