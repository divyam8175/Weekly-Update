
class Solution {
public:
bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
    int pillsUsed=0;
    multiset<int>s(workers.begin(),(workers.begin()+mid));
    for(int i=mid-1;i>=0;i--) {
        int task=tasks[i];
        auto it=prev(s.end());
        if(*it>=task) {
            s.erase(it);
        }else if(pillsUsed >= pills) {
            return false;
        }else {
            auto weak=s.lower_bound(task-strength);
            if(weak == s.end()) {
                return false;
            }

            s.erase(weak);
            pillsUsed++;
        }
    }
    return true;
}
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m=tasks.size();
        int n=workers.size();

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());

        int l=0;
        int h=min(n,m);
        int result=0;

        while(l<=h) {
            int mid=l+(h-l)/2;

            if(check(tasks,workers,pills,strength,mid)){
                result=mid;
                l=mid+1;
            }else {
                h=mid-1;
            }
        }
        return result;
    }
};