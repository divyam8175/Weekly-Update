class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(),beans.end());
        vector<long long>left(n,0);
        vector<long long>right(n,0);
        left[0]=0;
        for(int i=1;i<n;i++) {
            left[i]=left[i-1]+beans[i-1];
        }
        right[n-1]=0;
        for(int i=n-2;i>=0;i--) {
            long long diff=beans[i+1]-beans[i];
            right[i]=right[i+1]+((n-i-1)*diff);
        }
        long long mini=LLONG_MAX;
        for(int i=0;i<n;i++) {
            mini=min(mini,(left[i]+right[i]));
        }
        return mini;
    }
};