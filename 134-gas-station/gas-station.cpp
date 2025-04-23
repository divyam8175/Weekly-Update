class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalearn=accumulate(gas.begin(),gas.end(),0);
        int totalspend=accumulate(cost.begin(),cost.end(),0);

        if(totalspend>totalearn) return -1;
        int total=0;
        int index=0;
        for(int i=0;i<gas.size();i++) {
            total+=gas[i]-cost[i];
            if(total<0) {
                total=0;
                index=i+1;
            }
        }
        return index;
    }
};