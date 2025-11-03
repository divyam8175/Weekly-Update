class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0;
        int j=1;
        int n=colors.size();
        int total=0;
        while(i<n && j<n) {
            int sum=neededTime[i];
            int maxi=neededTime[i];
            while(colors[i] == colors[j]) {
                maxi=max(maxi,neededTime[j]);
                sum+=neededTime[j];
                j++;
            }
            if(j!=i+1)
            total+=(sum-maxi);
            i=j;
            j++;
        }
        return total;
    }
};