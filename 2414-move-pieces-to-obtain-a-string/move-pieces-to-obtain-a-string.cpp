class Solution {
public:
    bool canChange(string start, string target) {
        int i=0;
        int j=0;
        int n=start.size();
        int m=target.size();
        while(i<n && j<m) {
            while(start[i] == '_') i++;
            while(target[j] == '_') j++;
            if(i<n && j<m && (start[i] == target[j])&& (start[i] == 'L') && i>=j) {
                i++;j++;
            } else if( i<n && j<m && (start[i] == target[j])&& (start[i] == 'R') && i<=j) {
                i++;
                j++;
            }else {
                if(i>=n && j>=m) continue;
                return false;
            }
        }
        while(i<n) {
            if(start[i] == '_') i++;
            else return false;
        }
        while(j<n) {
            if(target[j] == '_') j++;
            else return false;
        }
        return true;
    }
};