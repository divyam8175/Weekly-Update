class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n>k && m>k) return 0;
        if(n<k && m<k) return 0;
        vector<int>ans1;
        vector<int>ans2;
        long long total=1;
        while(n>k) {
            if(n>=1)
            ans1.push_back(k);
            n=n-k;
        }
        if(n>=1 && ans1.size()>0)
        ans1.push_back(n);
        while(m>k) {
            if(m>=1)
            ans2.push_back(k);
            m=m-k;
        }
        if(m>=1 && ans2.size()>0)
        ans2.push_back(m);
        // cout<<ans1.size()<<" "<<ans2.size();
        for(int i=0;i<ans1.size();i++) {
            cout<<ans1[i]<<endl;
            total*=ans1[i];
        }
        cout<<endl;
        for(int i=0;i<ans2.size();i++) {
            cout<<ans2[i]<<endl;
            total*=ans2[i];
        }
        if(ans1.size()==0 && ans2.size()==0) return 0;
        return total;
    }
};