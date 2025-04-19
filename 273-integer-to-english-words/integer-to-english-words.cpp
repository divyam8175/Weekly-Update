class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<string> place{"Billion", "Million", "Thousand", ""};

        vector<string> number{"",        "One",       "Two",      "Three",
                              "Four",    "Five",      "Six",      "Seven",
                              "Eight",   "Nine",      "Ten",      "Eleven",
                              "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                              "Sixteen", "Seventeen", "Eighteen", "Nineteen",
                              "Twenty"};

        reverse(place.begin(), place.end());

        unordered_map<int, string> mpp;
        for (int i = 0; i < number.size(); i++) {
            mpp[i] = number[i];
        }
        mpp[30] = "Thirty";
        mpp[40] = "Forty";
        mpp[50] = "Fifty";
        mpp[60] = "Sixty";
        mpp[70] = "Seventy";
        mpp[80] = "Eighty";
        mpp[90] = "Ninety";
        int index = 0;
        string ans = "";
        while (num > 0) {
            int rem = num % 1000;
            num = num / 1000;
            int a = rem % 100;
            rem = rem / 100;
            int c = rem % 10;
            rem = rem / 10;
            string res = "";
            // cout<<a<<" "<<c<<endl;
            if (a != 0) {
                if (a < 10) {
                    if (res.size() != 0)
                        res = mpp[a] + " " + res;
                    else
                        res = mpp[a] + res;
                } else if (a <= 20) {
                    if (res.size() != 0)
                        res = mpp[a] + " " + res;
                    else
                        res = mpp[a] + res;
                } else {
                    if (a % 10 == 0) {
                        if (res.size() != 0)
                            res = mpp[a] + " " + res;
                        else
                            res = mpp[a] + res;
                    } else {
                        int b = a % 10;
                        a = a / 10;
                        if (res.size() != 0 && b != 0)
                            res = mpp[a * 10] + " " + mpp[b] + " " + res;
                        else
                            res = mpp[a * 10] + " " + mpp[b] + res;
                    }
                }
            }
            if (c != 0) {
                if (res.size() != 0)
                    res = mpp[c] + " " + "Hundred" + " " + res;
                else
                    res = mpp[c] + " " + "Hundred" + res;
            }
            // cout << res << endl;
            if (res.size() != 0)
                res = res + " " + place[index];
            // cout << res << endl << endl;
            if (ans.size() != 0 && res.size()!=0)
                ans = res + " " + ans;
            else
                ans = res + ans;
            cout<<ans<<endl;
            index++;
        }
        int j = ans.size() - 1;
        while (j >= 0 && ans[j] == ' ')
            j--;
        return ans.substr(0, j + 1);
    }
};