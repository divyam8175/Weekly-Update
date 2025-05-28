class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        for (int i = 0; i < words.size(); i++) {
            mpp[words[i]]++;
        }
        int count = 0;
        bool flag = true;
        for (auto itr : mpp) {
            if (itr.second > 0) {
                string a = itr.first;
                string b = itr.first;
                reverse(b.begin(), b.end());
                if (a[0] == a[1]) {
                    if(mpp[a] > 1) {
                    count += (mpp[a] / 2) * 4;
                    mpp[a]=mpp[a]-(mpp[a] / 2)*2;
                    if(mpp[a] > 0 && flag) {
                        count+=2;
                        flag=false;
                    }
                    }else {
                        if(flag==true) {
                            count+=2;
                            flag=false;
                        }
                    }
                    mpp[a] = 0;
                    mpp[b] = 0;
                    cout << a << " " << b << endl;
                } else {
                    if (mpp.find(b) != mpp.end()) {
                        count += min(mpp[a], mpp[b]) * 4;
                        mpp[a] = 0;
                        mpp[b] = 0;
                    }
                    cout << a << " " << b << endl;
                }
            }
        }
        // if (flag == false)
        //     count += 2;
        return count;
    }
};