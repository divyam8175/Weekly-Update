class Solution {
public:
    int reverse(int n) {
        int no = 0;
        while (n > 0) {
            int rem = n % 10;
            no = no * 10 + rem;
            n = n / 10;
        }
        return no;
    }
    int absmini(vector<int> a, vector<int> b) {
        if (a.empty() || b.empty())
            return -1;

        sort(b.begin(), b.end()); // sort b for upper_bound

        int best = INT_MAX;

        for (int x : a) {
            auto it = upper_bound(b.begin(), b.end(), x);
            // upper_bound gives first element > x

            if (it != b.end()) {
                best = min(best, abs(*it - x));
                if (best == 0)
                    return 0;
            }
            // NOTE: no previous element checking, because we only want just
            // greater
        }

        return (best == INT_MAX ? INT_MAX : best);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }
        int mini = INT_MAX;
        for (auto itr : mpp) {
            if (itr.second.size() == 0)
                continue;
            int rev = reverse(itr.first);
            if (mpp.find(rev) != mpp.end()) {
                int m = absmini(itr.second, mpp[rev]);
                mini = min(mini, m);
                itr.second.clear();
            }
        }
        return mini==INT_MAX? -1 : mini;
    }
};