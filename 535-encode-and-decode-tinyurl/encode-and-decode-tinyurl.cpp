class Solution {
public:
unordered_map<string,string>mpp;
string ans="https://urlshortner";
int i =0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mpp[ans+to_string(i)]=longUrl;
        return ans+to_string(i++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));