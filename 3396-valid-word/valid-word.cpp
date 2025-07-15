class Solution {
public:
    bool isValid(string word) {
        int charcount = 0;
        int lc = 0;
        int uc = 0;
        int dg = 0;
        int vo = 0;
        int con = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= '0' && word[i] <= '9') {
                dg++;
                charcount++;
            } else if ((word[i] >= 'a' && word[i] <= 'z') ||
                       (word[i] >= 'A' && word[i] <= 'Z')) {
                charcount++;
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                    word[i] == 'o' || word[i] == 'u' || word[i] == 'A' ||
                    word[i] == 'E' || word[i] == 'I' || word[i] == 'O' ||
                    word[i] == 'U')
                    vo++;
                else
                    con++;
            } else {
                return false;
            }
        }
        // cout<<"hi";
        if(charcount>=3 && vo>=1 && con>=1) return true;
        return false;
    }
};