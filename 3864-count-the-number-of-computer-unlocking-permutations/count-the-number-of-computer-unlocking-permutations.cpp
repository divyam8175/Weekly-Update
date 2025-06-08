class Solution {
public:
int mod=1000000007;
long long factorial(int n) {
    return (n==1 || n==0) ? 1: (n * factorial(n - 1))%mod; 
}
    int countPermutations(vector<int>& complexity) {
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mpp;
        for(int i=0;i<complexity.size();i++) {
            pq.push(complexity[i]);
            mpp[complexity[i]]++;
        }
        cout<<pq.top();
        if(pq.top() != complexity[0]) return 0;
        if(mpp[pq.top()] > 1) return 0;
        long long n=complexity.size()-1;
        return factorial(n)%mod;
    }
};