class Solution {
public:
    string concatHex36(int n) {
        string s13="";
        string s36="";
        int temp=n*n;
        while(temp>0) {
            int rem=temp%16;
            if(rem < 10) {
            s13.push_back(rem+'0');
            }else {
                rem=rem-10;
                s13.push_back('A'+rem);
            }
            temp=temp/16;
        }
        reverse(s13.begin(),s13.end());
        temp=n*n*n;
        while(temp>0) {
            int rem=temp%36;
            if(rem < 10) {
                s36.push_back(rem+'0');
            }else {
                rem=rem-10;
                s36.push_back('A'+rem);
            }
            temp=temp/36;
        }
        reverse(s36.begin(),s36.end());
        // cout<<s13<<" "<<s36<<endl; 
        return s13+s36;
    }
};