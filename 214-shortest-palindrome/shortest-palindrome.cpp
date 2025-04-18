class Solution {
public:
 int kmp(const string &txt, const string &patt) {
        string newString = patt + '#' + txt;
        vector<int> pi(newString.length(), 0);
        int i = 1, k = 0;
        while (i < newString.length()) {
            if (newString[i] == newString[k]) {
                k++;
                pi[i] = k;
                i++;
            } else {
                if (k > 0) {
                    k = pi[k - 1];
                } else {
                    pi[i] = 0;
                    i++;
                }
            }
        }
        return pi.back();
    }
    string shortestPalindrome(string s) {
        string ans=s;
        reverse(ans.begin(),ans.end());
        int count = kmp(ans, s);
        return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
    }
};