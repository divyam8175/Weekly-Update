class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int i = 0;
        int j = n - 1;
        int count = 0;
        int a = capacityA;
        int b = capacityB;
        while (i < j) {
            if (a < plants[i]) {
                count++;
                a = capacityA;
            }
            if (b < plants[j]) {
                count++;
                b = capacityB;
            }
            cout<<a<<" "<<b;
            a=a-plants[i];
            b=b-plants[j];
            i++;
            j--;
        }
        if(i==j) {
            if(plants[i] <= a || plants[j] <= b)  {

            }else {
                count++;
            }
        }
        return count;
    }
};