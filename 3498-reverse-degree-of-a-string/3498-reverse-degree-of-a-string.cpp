class Solution {
public:
    int reverseDegree(string s) {
        long long ans = 0;
        for(int i = 0; i<s.length();i++){
            char c = s[i];
            int ascii = 26-(c-'a');
            ans += (ascii * (i+1));
        }
        return ans;
    }
};