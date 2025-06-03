
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();

        vector<int>left(n,-1);
        vector<int>right(n,-1);

        for(int i=0;i<n;i++) {
            if(dominoes[i] == 'R') {
                right[i] = i;
            }else if(dominoes[i] == 'L') {
                right[i]=-1;
            }else  {
                if(i-1>=0)
                right[i]=right[i-1];
            }
        }


        for(int i=n-1;i>=0;i--) {
            if(dominoes[i] == 'L') {
                left[i] = i;
            }else if(dominoes[i] == 'R') {
                left[i]=-1;
            }else {
                if(i+1<n)
                left[i]=left[i+1];
            }
        }

        for(int i=0;i<n;i++) {
            int leftDist=abs(i-right[i]);
            int rightDist=abs(i-left[i]);

            if(right[i] == left[i]) {
                dominoes[i]='.';
            }else if(right[i] == -1) {
                dominoes[i]='L';
            }else if(left[i] == -1) {
                dominoes[i]='R';
            } else if(leftDist == rightDist) {
                dominoes[i]='.';
            }else {
                dominoes[i]=leftDist>rightDist?'L':'R';
            }
        }
        return dominoes;
    }
};