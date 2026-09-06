class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // dp[j] stores the number of subsequences of s matching t[0...j-1]
        // Using unsigned long long to avoid 32-bit signed integer overflow during intermediate additions
        vector<unsigned long long> dp(m + 1, 0);
        
        // Base case: dp[0] = 1 (matching empty string t)
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            // Right-to-left iteration to use previous row values without extra space
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        
        return dp[m];
    
    }
};