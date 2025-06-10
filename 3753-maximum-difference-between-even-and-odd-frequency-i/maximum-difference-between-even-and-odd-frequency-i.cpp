class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++) mpp[s[i]]++;
        vector<int>even;
        vector<int>odd;
        for(auto itr:mpp) {
            if(itr.second%2) {
                odd.push_back(itr.second);
            } else {
                even.push_back(itr.second);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int maxi1=(even[0]-odd[odd.size()-1]);
        int maxi2=(odd[odd.size()-1]-even[0]);
        return maxi2;
    }
};