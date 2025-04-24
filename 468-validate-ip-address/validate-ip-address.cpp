class Solution {
public:
bool isvalidip4(string a){
    if(a.size() > 1 && a[0] == '0') return false;
    for(int i=0;i<a.size();i++) {
        if(a[i] >= '0' && a[i] <= '9'){

        }else {
            return false;
        }
    }
    int b=stoi(a);
    cout<<b<<endl;
    if(b < 0 || b>255) return false;
    return true;
}
bool isvalidip6(string a){
    if(a.size()<1 || a.size() >4) return false;
    for(int i=0;i<a.size();i++) {
        if(a[i] >= '0' && a[i] <= '9') {

        }else if(a[i] >= 'a' && a[i] <= 'f') {

        }else if(a[i] >= 'A' && a[i] <= 'F'){

        }else {
            return false;
        }
    }
    // cout<<b<<endl;
    return true;
}
    string validIPAddress(string q) {
        int n=q.size();
        if(n>39) return "Neither";
        if(q.contains('.')) {
            int dotcount=0;
            int gapcount=0;
            q.push_back('.');
            string ans="";
            for(int i=0;i<q.size();i++) {
                if(q[i] == '.') {
                    dotcount++;
                    if(dotcount>4) return "Neither";
                    if(ans.size()>0) {
                        gapcount++;
                        if(gapcount>4) return  "Neither";
                        if(isvalidip4(ans)) {
                            ans="";
                            continue;
                        }else {
                            return "Neither";
                        }
                    }else {
                        return "Neither";
                    }
                }
                ans.push_back(q[i]);
            }
            cout<<dotcount<<" "<<gapcount<<endl;
            if(dotcount < 4) return "Neither";
            if(gapcount < 4) return "Neither";
            return "IPv4";
        } else  if(q.contains(':')) {
            int coloncount=0;
            int gapcount=0;
            q.push_back(':');
            string ans="";
            for(int i=0;i<q.size();i++) {
                if(q[i] == ':') {
                    coloncount++;
                    if(coloncount>8) return "Neither";
                    if(ans.size()>0) {
                        gapcount++;
                        if(gapcount>8) return  "Neither";
                        if(isvalidip6(ans)) {
                            ans="";
                            continue;
                        }else {
                            return "Neither";
                        }
                    }else {
                        return "Neither";
                    }
                }
                ans.push_back(q[i]);
            }
            cout<<coloncount<<" "<<gapcount<<endl;
            if(coloncount < 8) return "Neither";
            if(gapcount < 8) return "Neither";
            return "IPv6";
        }

        return "Neither";
    }
};