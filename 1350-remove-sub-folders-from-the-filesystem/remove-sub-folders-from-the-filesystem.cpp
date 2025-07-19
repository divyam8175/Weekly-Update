class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_map<string, int> mpp;
        vector<string> ans;
        int n = folder.size();
        for (int i = 0; i < n; i++) {
            string a = folder[i];
            string b = "";
            bool flag = false;
            for (int j = 0; j < a.size(); j++) {
                if (a[j] == '/') {
                    continue;
                } else {
                    while (j+1 < a.size() && a[j + 1] != '/') {
                        b.push_back(a[j]);
                        j++;
                    }
                    b.push_back(a[j]);
                }
                b.push_back('-');
                if (mpp[b] > 0) {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                mpp[b]++;
                ans.push_back(a);
            }
        }
        return ans;
    }
};