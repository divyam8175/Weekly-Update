class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n=nums.size();
        long long posi1=nums[n-1];
        long long posi2=nums[n-2];
        // long long posi3=nums[n-3];

        long long neg1= nums[0];
        long long neg2= nums[1]; 

        long long maxi1=posi1*posi2*100000;
        long long maxi2=neg1*neg2*100000;
        long long maxi3=posi1*neg1*(-100000);

        return max({maxi1,maxi2,maxi3});

        // vector<int>temp;
        // if(posi1 > 0) temp.push_back(posi1);
        // if(posi2 > 0) temp.push_back(posi2);
        // if(posi3 > 0) temp.push_back(posi3);
        // if(neg1 > 0 && neg 2 > 0) temp.push_back(neg1);
        // // if(neg2 > 0) temp.push_back(neg2);

        // if(temp.size() <= 1) return 0;

        // if(temp.size() == 2) 

        // int zero=0;
        // int neg=0;
        // int pos=0;
        // if(posi1 == 0) zero++;
        // else if (posi1 < 0) neg++;
        // else pos++;

        // if(posi2 == 0) zero++;
        // else if (posi2 < 0) neg++;
        // else pos++;

        // if(posi3 == 0) zero++;
        // else if (posi3 < 0) neg++;
        // else pos++;

        // if(neg1) == 0) zero++;
        // else if (neg1 < 0) neg++;
        // else pos++;

        // if(neg2 == 0) zero++;
        // else if (neg2 < 0) neg++;
        // else pos++;

        // if(zero >= 4) return 0;

        // if(neg == 2 && pos >=  2) {
        //     long long maxi1=neg1*neg2*100000;
        //     long long maxi2=pos1*pos2*100000;

        //     return maxi(maxi1,maxi2);
        // }else if(neg != 2 && pos >= 2 ) {
        //     return pos1*pos2*100000;
        // }else if(neg ==2 && pos < 2) {
        //     return neg1*neg2*100000;
        // }else {

        // }

    }
};