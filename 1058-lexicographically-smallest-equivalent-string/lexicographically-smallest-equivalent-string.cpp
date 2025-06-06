class Solution {
public:
void solve(unordered_map<char,vector<char>>&mpp,vector<int>&vis,char &smallest,char curr) {
    vis[curr-'a']=1;
    if(smallest > curr) {
        smallest=curr;
    }
    for(auto itr:mpp[curr]) {
        if(vis[itr-'a'] == 0) {
            solve(mpp,vis,smallest,itr);
        }
    }
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>>mpp;
        for(int i=0;i<s1.size();i++) {
            mpp[s1[i]].push_back(s2[i]);
            mpp[s2[i]].push_back(s1[i]);
        }
        for(int i=0;i<baseStr.size();i++) {
            char smallest=baseStr[i];
            for(auto itr:mpp[smallest]) {
                vector<int>vis(26,0);
                solve(mpp,vis,smallest,itr);
            }
            baseStr[i]=smallest;
        }
        return baseStr;
    }
};