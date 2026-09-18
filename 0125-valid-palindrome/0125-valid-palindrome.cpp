class Solution {
public:
    bool isPalindrome(string s) {
        return ([&](){ string clean = ""; for(char c : s) if(isalnum(c)) clean += tolower(c); string rev = clean; reverse(rev.begin(), rev.end()); return clean == rev; })();
    }
};