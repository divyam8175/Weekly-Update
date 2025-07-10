class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>mpp;
        while(n!=1) {
            int sum=0;
            while(n>0) {
                int rem=n%10;
                sum+=(rem*rem);
                n=n/10;
            }
            if(mpp[sum] != 0) return false;
            else mpp[sum]++;
            n=sum;
        }
        return true;
    }
};