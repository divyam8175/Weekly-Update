class Solution {
public:
int isvalid(vector<int>&d,int m,int lower,int upper) {
    int sum=m;
    for(int i=0;i<d.size();i++){
            sum=sum+d[i];
        if(sum >= lower && sum<=upper) {
            continue;
        } else if(sum > upper) {
            return 1;
        }else {
            return -1;
        }
    }
    return 0;
}
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        int l=lower;
        int h=upper;
        int m=(l+h)/2;
        int ans1=INT_MIN;
        while(l<=h) {
            int a=isvalid(d,m,lower,upper);
            cout<<a<<" "<<m<<endl;
            if(a==0){
                ans1=m;
                h=m-1;
            }else if(a==1) {
                h=m-1;;
            }else {
                l=m+1;
            }
            m=(l+h)/2;
        }
        cout<<endl;
        int ans2=INT_MIN;
        l=lower;
        h=upper;
        m=(l+h)/2;
        while(l<=h) {
            int a=isvalid(d,m,lower,upper);
            cout<<a<<" "<<m<<endl;
            if(a==0){
                ans2=m;
                l=m+1;
            }else if(a==1) {
                h=m-1;;
            }else {
                l=m+1;
            }
            m=(l+h)/2;
        }
        cout<<ans1<<" "<<ans2<<endl;
        if(ans1 == INT_MIN || ans2==INT_MIN) return 0;
        return ans2-ans1+1;
    }
};