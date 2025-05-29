class Solution {
public:
    bool isprime(long long a) {
        if(a==2 || a==3) return true;
        for(long long i=2;i*i<=a;i++) {
            if(a%i==0) {
                return false;
            }
        }
        return true;
    }
    long long convert(string p) {
        long long no=0;
        for(int i=0;i<p.size();i++) {
            no=no*10+(p[i]-'0');
        }
        return no;
    }
    long long sumOfLargestPrimes(string s) {
        long long sum=0;
        int count=0;
        set<long long,greater<long long>>pq;
        for(int i=0;i<s.size();i++) {
            for(int j=1;j<=s.size()-i;j++) {
                string p=s.substr(i,j);
                long long no=convert(p);
                // cout<<no<<e/ndl;
                if(isprime(no)) {
                       pq.insert(no); 
                }
                if(count==3) {
                    break;
                }
            }
        }
        int a=3;
        count=0;
        for(auto itr:pq) {
            if(itr!=1) {
            count++;
            sum+=itr;
            }
            // cout<<itr<<endl;
            if(count==3) break;
        }
        return sum;
    }
};