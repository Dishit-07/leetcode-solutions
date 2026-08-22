#include <sstream>

class Solution {
public:
    string reverseWords(string s) {
        return [&](){ stringstream ss(s); string word, ans = ""; while(ss >> word) ans = word + (ans.empty() ? "" : " ") + ans; return ans; }();
    }
};