class Solution {
public:
    int solve(map<int, set<int>> mp, int x) {
        int total = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            set<int>s=it->second;
            bool flag = false;
            for (auto itr = s.rbegin(); itr != s.rend(); ++itr) {
                total+=((*itr) * it->first);
                x--;
                if(x==0) {
                    flag=true;
                    break;
                }
            }
            if(flag || x == 0) {
                break;
            }
        }
        return total;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> no_to_grup;
        map<int, set<int>> grup_to_list;

        int index = k - 1;
        for (int i = 0; i <= index; i++) {
            if (no_to_grup.find(nums[i]) == no_to_grup.end()) {
                no_to_grup[nums[i]]++;
                grup_to_list[1].insert(nums[i]);
            } else {
                int grup_no = no_to_grup[nums[i]];
                grup_to_list[grup_no].erase(nums[i]);
                no_to_grup[nums[i]] = grup_no + 1;
                grup_to_list[grup_no + 1].insert(nums[i]);
            }
        }
        for (auto itr : no_to_grup) {
            cout << itr.first << " " << itr.second << endl;
        }
        cout << endl << endl;
        for (auto itr : grup_to_list) {
            cout << itr.first << endl;
            for (auto it : itr.second) {
                cout << it << " ";
            }
            cout << endl;
        }

        int i = 0;
        int j = index;
        vector<int> ans;
        while (j < nums.size()) {
            int temp = solve(grup_to_list, x);
            ans.push_back(temp);

            int no1 = nums[i++];
            int grup_no = no_to_grup[no1];
            grup_to_list[grup_no].erase(no1);
            no_to_grup[no1] = grup_no - 1;
            grup_to_list[grup_no-1].insert(no1);
            j++;
            if (j >= nums.size())
                break;
            if (no_to_grup.find(nums[j]) == no_to_grup.end()) {
                no_to_grup[nums[j]]++;
                grup_to_list[1].insert(nums[j]);
            } else {
                int grup_no = no_to_grup[nums[j]];
                grup_to_list[grup_no].erase(nums[j]);
                no_to_grup[nums[j]] = grup_no + 1;
                grup_to_list[grup_no + 1].insert(nums[j]);
            }
        }
        return ans;
    }
};