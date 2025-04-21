class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<groupSizes.size();i++) mpp[groupSizes[i]].push_back(i);
        for(auto itr:mpp) {
            if(itr.first >= itr.second.size()) {
                vector<int>res;
                for(int i=0;i<itr.second.size();i++) {
                    res.push_back(mpp[itr.first][i]);
                }
                ans.push_back(res);
            }else {
                int n=itr.second.size();
                for(int i=0;i<n;i=i+itr.first) {
                vector<int>res;
                    for(int j=i;j<i+itr.first;j++) {
                        res.push_back(mpp[itr.first][j]);
                    }
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};