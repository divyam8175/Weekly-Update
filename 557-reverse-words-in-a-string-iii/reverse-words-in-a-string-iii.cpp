class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0;
        int j=0;
        while(j<s.size()) {
            if(s[j] == ' ') {
                string p=s.substr(i,j-i);
                reverse(p.begin(),p.end());
                ans+=p+' ';
                i=j+1;
            }
            j++;
        }
        string p=s.substr(i,j-i);
        reverse(p.begin(),p.end());
        ans+=p;
        return ans;
    }
};