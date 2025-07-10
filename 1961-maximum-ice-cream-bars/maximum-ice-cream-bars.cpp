class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>temp=costs;
        sort(temp.begin(),temp.end());
        int sum=0;
        int count=0;
        for(int i=0;i<temp.size();i++) {
            sum+=temp[i];
            count++;
            if(sum==coins) return count;
            else if(sum>coins) return count-1;
        }
        return count;
    }
};