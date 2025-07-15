class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>index(26,-1);
        for(int i=0;i<order.size();i++) {
            index[order[i]-'a']=i;
        }
        auto my_comparator=[&index](char& ch1,char& ch2) {
            return index[ch1-'a']<index[ch2-'a'];
        };
        sort(s.begin(),s.end(),my_comparator);
        return s;
    }
};