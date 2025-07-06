class FindSumPairs {
public:
    unordered_map<int, int> mpp1;
    unordered_map<int, int> mpp2;
    vector<int> nums;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); i++) {
            mpp1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            mpp2[nums2[i]]++;
        }
        for (int j = 0; j < nums2.size(); j++) {
            nums.push_back(nums2[j]);
        }
    }

    void add(int index, int val) {
        int no = nums[index];
        int freq = mpp2[no];
        mpp2[no]--;
        if (mpp2[no] == 0)
            mpp2.erase(no);
        mpp2[no + val]++;
        nums[index] += val;
    }

    int count(int tot) {
        int cnt = 0;
        for (auto itr : mpp1) {
            int no = itr.first;
            int freq = itr.second;
            int temp = tot - no;
            if (mpp2[temp] > 0) {
                cnt += (freq * mpp2[temp]);
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */