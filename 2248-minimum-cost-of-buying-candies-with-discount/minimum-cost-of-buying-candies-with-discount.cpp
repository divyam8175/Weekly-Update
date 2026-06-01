class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum=0;
        if(cost.size() == 2) {
            return cost[0]+cost[1];
        } 
        if(cost.size() == 1) {
            return cost[0];
        }
        sort(cost.begin(),cost.end());
        int j=0;
        for(int i=cost.size()-1;i>=0;i--) {
            j++;
            if(j%3==0 && j!=0) continue;
            else sum=sum+cost[i];
        }
        return sum;
    }
};