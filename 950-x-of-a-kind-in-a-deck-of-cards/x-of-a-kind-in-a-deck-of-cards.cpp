class Solution {
public:
bool solve(unordered_map<int,int>mpp,int i) {
    for(auto itr:mpp) {
        if(itr.second%i != 0) return false;
    }
    return true;
}
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mpp1;
        int mini=INT_MAX;
        for(int i=0;i<deck.size();i++) {
            mpp1[deck[i]]++;
        }
        int maxi=0;
        for(auto itr:mpp1) {
            maxi=max(maxi,itr.second);
        }
        for(int i=2;i<=maxi;i++) {
            if(solve(mpp1,i)) {
                return true;
            }
        }
        // int even=0;
        // int odd=0;
        // int prime=0;
        // for(auto itr:mpp) {
        //     if(itr.second<=1) return false;
        //     if(itr.second%3==0) {
        //         odd++;
        //     }
        //     else {
        //         prime++;
        //     }
        // }
        // for(auto itr:mpp) {
        //     if(itr.second<=1) return false;
        //     if(itr.second%2==0) {
        //         even++;
        //     }
        //     else {
        //         prime++;
        //     }
        // }
        // cout<<even<<" "<<odd<<" "<<prime<<endl;
        // if(mpp.size() == even) return true;
        // if(mpp.size() == odd) return true;
        // if(mpp.size() == prime/2) return true;
        return false;
    }
};