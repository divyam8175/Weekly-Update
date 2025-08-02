class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>mpp;
        int n=word.size();
        for(int i=0;i<n;i=i+k) {
            string a=word.substr(i,k);
            mpp[a]++;
        }
        int maxi=-1;
        string temp="";
        for(auto itr:mpp) {
            if(itr.second > maxi) {
                maxi=itr.second;
                temp=itr.first;
            }
        }
        int i=0;
        int count=0;
        while(i<n) {
            if(word.substr(i,k) != temp) count++;
            i=i+k;
        }
        return count;
    }
};