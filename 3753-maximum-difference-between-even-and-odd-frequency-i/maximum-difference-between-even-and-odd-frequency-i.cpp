class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++) mpp[s[i]]++;
        int evenmini=INT_MAX;
        int oddmaxi=INT_MIN;
        for(auto itr:mpp) {
            if(itr.second%2) {
                oddmaxi=max(oddmaxi,itr.second);
            } else {
                evenmini=min(evenmini,itr.second);
            }
        }
        return oddmaxi-evenmini;
    }
};