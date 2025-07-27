class Solution {
public:
    int maximumLength(vector<int>& nums) {
        set<int> s;
        for (auto itr : nums) {
            if (itr != 1)
                s.insert(itr);
        }
        unordered_map<int, int> mpp;
        for (auto itr : nums)
            mpp[itr]++;
        int maxi = -1;
        for (auto itr : s) {
            long long key = itr;
            int count = 0;
            while (mpp[key] >= 1) {
                if(mpp[key] == 1) {
                    count+=1;
                    break;
                }
                count += 2;
                if(key*key > INT_MAX) break;
                long long int temp=key*key;
                key = temp;
            }
            if (count > 2) {
                if (count % 2 == 0) {
                    maxi = max(maxi, count-1);
                } else {
                    maxi = max(maxi, count);
                }
            }
        }
        int ans = mpp[1];
        if (ans % 2 == 0) {
            maxi = max(maxi, ans - 1);
        } else {
            maxi = max(maxi, ans);
        }
        return maxi==-1?1:maxi;
    }
};