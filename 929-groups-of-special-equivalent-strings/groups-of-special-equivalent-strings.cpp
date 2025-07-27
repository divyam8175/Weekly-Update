class Solution {
public:
static bool customCompare(const char &a,const char &b) {
    return a > b;
}

void sortOddIndexChars(string& s) {
    vector<char> oddChars;
    for (int i = 1; i < s.length(); i += 2) {
        oddChars.push_back(s[i]);
    }
    sort(oddChars.begin(), oddChars.end(), customCompare);
    int idx = 0;
    for (int i = 1; i < s.length(); i += 2) {
        s[i] = oddChars[idx++];
    }
}
void sortEvenIndexChars(string& s) {
    vector<char> evenChars;
    for (int i = 0; i < s.length(); i += 2) {
        evenChars.push_back(s[i]);
    }
    sort(evenChars.begin(), evenChars.end(), customCompare);
    int idx = 0;
    for (int i = 0; i < s.length(); i += 2) {
        s[i] = evenChars[idx++];
    }

}
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map<string,int>mpp;
        for(int i=0;i<words.size();i++) {
            sortOddIndexChars(words[i]);
            sortEvenIndexChars(words[i]);
            mpp[words[i]]++;
        }
        return mpp.size();
    }
};