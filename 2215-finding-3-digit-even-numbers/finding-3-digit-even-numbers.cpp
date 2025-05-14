class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>mpp;
        vector<int>result;
        for(int i=0;i<digits.size();i++) mpp[digits[i]]++;
        for(int i=1;i<=9;i++) {
            if(mpp[i] == 0) continue;
            mpp[i]--;

            for(int j=0;j<=9;j++) {
                if(mpp[j] == 0) continue;
                mpp[j]--;

                for(int k=0;k<=9;k++) {
                    if(mpp[k] == 0 || k%2==1) continue;
                    mpp[k]--;

                    int num=(i*100)+(j*10)+(k);

                    result.push_back(num);

                    mpp[k]++;
                }
                mpp[j]++;
            }
            mpp[i]++;
        }
        return result;
    }
};