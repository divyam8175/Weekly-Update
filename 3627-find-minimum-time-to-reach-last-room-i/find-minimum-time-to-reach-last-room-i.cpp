class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();

        int x[4]={-1, 1, 0, 0};
        int y[4]={0, 0, -1, 1};

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vis[0][0]=true;
        pq.push({0 , {0, 0}});
        while(!pq.empty()) {
            auto p=pq.top();
            pq.pop();
            int w=p.first;
            int a=p.second.first;
            int b=p.second.second;

            if(a==n-1 && b==m-1) {
                return w;
            }
            for(int i=0;i<4;i++) {
                int newa=a+x[i];
                int newb=b+y[i];
                if(newa>=0 && newa<n && newb>=0 && newb<m && vis[newa][newb] == false) {
                    vis[newa][newb]=true;
                    pq.push({max(w,moveTime[newa][newb])+1,{newa,newb}});
                }
            }
        }
        return -1;
    }
};