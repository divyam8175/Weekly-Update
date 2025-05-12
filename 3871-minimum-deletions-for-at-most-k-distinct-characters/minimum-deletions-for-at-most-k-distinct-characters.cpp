class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++) mpp[s[i]]++;
        vector<int>s1;
        for(auto itr:mpp) {
            s1.push_back(itr.second);
        }
        sort(s1.begin(),s1.end());
        if(mpp.size() <= k)  return 0;
        int size=0;
        int total=0;
        for(auto itr:s1) {
            if(mpp.size() - size == k) return total;
            size++;
            total+=itr;
        }
        return 0;
    }
};