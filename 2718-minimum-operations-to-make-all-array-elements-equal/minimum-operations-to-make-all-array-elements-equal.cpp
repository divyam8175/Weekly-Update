class Solution {
public:
void print(vector<int>nums){
    cout<<"hi"<<endl;
    for(int i=0;i<nums.size();i++) {
        cout<<nums[i]<<" ";
    }
    cout<<"hi"<<endl;
}
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> ans;
        vector<long long> forward(n,0);
        vector<long long> backward(n,0);
        // print(nums);
        for (int i = 1; i < n; i++) {
            long long b=abs(nums[i]-nums[i-1]);
            long long c=i*b;

            forward[i]=(forward[i-1]);
            forward[i]+=c;
        }
        // print(forward);
        for (int i = n - 2; i >= 0; i--) {
            long long b=abs(nums[i]-nums[i+1]);
            long long c=(n-i-1)*b;
            backward[i]=(backward[i+1]);
            backward[i]+=c;
        }
        // print(backward);
        long long maxi = nums[n-1];
        long long mini = nums[0];
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i];
            if (a >= maxi) {
                long long diff=abs(nums[n-1]-a);
                ans.push_back(n*diff + forward[n-1]);
            } else if (a <= mini) {
                long long diff=abs(nums[0]-a);
                ans.push_back(n*diff + backward[0]);
            } else {
                int l = 0;
                int h = n - 1;
                while (l <= h) {
                    int mid = (l + h) / 2;
                    if (nums[mid] <= a) {
                        l=mid+1;
                    } else {
                        h=mid-1;
                    }
                }
                // cout<<n<<" "<<h<<" "<<l<<" "<<a<<" "<<nums[h]<<endl;
                long long sum=forward[h];
                sum+=backward[l];
                long long b=h+1;
                long long c=a-nums[h];
                long long d=(nums.size()-l);
                long long e=(nums[l]-a);
                long long f=b*c;
                long long g=d*e;
                long long final123=f+g;
                long long totalsum=final123;
                ans.push_back(totalsum+sum);
            }
        }
        return ans;
    }
};