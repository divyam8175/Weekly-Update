class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.size()-1;
        int count=0;
            while(i<j && s[i] == s[j]) {
                char t=s[i];
                while(i<=j && s[i] == t){
                    i++;
                }
                while(i<j && s[j] == t) {
                    j--;
                }
            }
        return j-i+1;
    }
};