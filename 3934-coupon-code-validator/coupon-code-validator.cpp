class Solution {
public:
bool checkstring(string a) {
    for(int i=0;i<a.size();i++) {
        if( (a[i] >= 'a' && a[i] <= 'z')  || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9') || (a[i] == '_')) {
            continue;
        }else{
            return false;
        }
    }
    return true;
}
bool checkline(string a,vector<string>& businessLine,int i) {
    if(businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant") return true;
    return false;
}
bool checkactive(string a,vector<bool>& isActive,int index) {
    return isActive[index];
}
    vector<string> validateCoupons(vector<string>& code,vector<string>& businessLine,vector<bool>& isActive) {
        map<string, vector<string>> mpp;
        mpp["electronics"].push_back("");
        mpp["grocery"].push_back("");
        mpp["pharmacy"].push_back("");
        mpp["restaurants"].push_back("");
        for(int i=0;i<code.size();i++){
            string a=code[i];
            // cout<<a<<endl;
            bool flag1=checkstring(a);
            bool flag2=checkline(a,businessLine,i);
            bool flag3=checkactive(a,isActive,i);
            // cout<<flag1<<" "<<flag2<<" "<<flag3<<endl;
            if(a.size() > 0 && flag1 && flag2 && flag3) {
                // cout<<a<<endl;
                mpp[businessLine[i]].push_back(code[i]);
            }
        }
        vector<string>ans;
        for (auto itr : mpp) {
            sort(itr.second.begin(),itr.second.end());
            for (auto it : itr.second) {
                if(it.size()>0) {
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};