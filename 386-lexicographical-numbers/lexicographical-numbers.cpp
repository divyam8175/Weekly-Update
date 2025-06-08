class Solution {
public:
struct mycomp {
    bool operator()(int a,int b) {
        string a1=to_string(a);
        string a2=to_string(b);
        return a1<a2;
    }
};
    vector<int> lexicalOrder(int n) {
        vector<int>v;
        for(int i=1;i<=n;i++) v.push_back(i);
        sort(v.begin(),v.end(),mycomp());
        return v;
    }
};