class Solution {
public:
string numtostring(int num) {
    string res="";
    while(num>0) {
        int rem=num%10;
        res.push_back('0'+rem);
        num=num/10;
    }
    reverse(res.begin(),res.end());
    return res;
}
int stringtonum(string num) {
    int ans=0;
    for(int i=0;i<num.size();i++) {
        ans=ans*10+(num[i]-'0');
    }
    return ans;
}
    int maxDiff(int num) {
        string s = numtostring(num);
        string s2=s;
        char c='q';
        for(int i=0;i<s.size();i++) {
            if(s[i]-'0' != 9) {
                c=s[i];
                break;
            }
        }
        cout<<c<<" "<<s<<" "<<s<<endl;
        for(int i=0;i<s.size();i++) {
            if(s[i] == c) {
                s[i]='9';
            }
        }
        int maxi=stringtonum(s);
        c=s2[0];
        char change='1';
        char first=s2[0];
        for(int i=0;i<s2.size();i++) {
            if(s2[i] == '0') continue;
            else if(i == 0 && s2[i] != '1'){
                c=s2[i];
                change='1';
                break;
            }else if(i == 0 && s2[i] == '1') {
                continue;
            }else {
                if(s2[i] == first) {
                    continue;
                }
                c=s2[i];
                change='0';
                break;
            }
        }
        for(int i=0;i<s2.size();i++) {
            if(s2[i] == c) {
                s2[i]=change;
            }
        }

        int mini = stringtonum(s2);
        cout<<maxi<<" "<<mini<<" "<<c<<endl;
        return maxi-mini;
    }
};