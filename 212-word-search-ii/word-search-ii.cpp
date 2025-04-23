class Solution {
public:
    int x[4] = {0, 0, -1, 1};
    int y[4] = {-1, 1, 0, 0};
    bool solve(vector<vector<char>>& board, int i, int j,
               unordered_set<string>& prefixes, set<string>& words,
               vector<vector<bool>>& used, vector<string>& res, string s) {
        s += ((board[i][j]));
        if (!prefixes.count(s)) {
            return false;
        }
        if (words.count(s)) {
            res.push_back(s);
            words.erase(s);
        }
        bool flag = false;
        used[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int newx = i + x[k];
            int newy = j + y[k];
            if (newx >= 0 && newx < board.size() && newy >= 0 &&
                newy < board[0].size() && used[newx][newy] == false) {
                flag =
                    solve(board, newx, newy, prefixes, words, used, res, s) ||
                    flag;
            }
        }
        used[i][j] = false;
        s.pop_back();
        return res.size();
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& wordsList) {
        unordered_set<string> prefixes;
        for (auto& w : wordsList) {
            for (int len = 1; len <= w.size(); len++)
                prefixes.insert(w.substr(0, len));
        }
        set<string> words(wordsList.begin(), wordsList.end());
        vector<string> ans;
        vector<vector<bool>> used(board.size(),
                                  vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                vector<string> res;
                string xyz(1, board[i][j]);
                if (!prefixes.count(xyz))
                    continue;
                bool flag = solve(board, i, j, prefixes, words, used, res, "");
                for (auto& w : res)
                    ans.push_back(w);
            }
        }
        return ans;
    }
};