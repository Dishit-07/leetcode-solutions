#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        
        // last[c] stores the number of distinct subsequences ending with character c
        vector<long long> last(26, 0);
        
        for (char c : s) {
            int idx = c - 'a';
            
            // Current total distinct subsequences + 1 (for single character 'c' itself)
            long long current_total = 1;
            for (int i = 0; i < 26; i++) {
                current_total = (current_total + last[i]) % MOD;
            }
            
            // Update the contribution of character 'c'
            last[idx] = current_total;
        }
        
        // Sum of all distinct subsequences across all characters
        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + last[i]) % MOD;
        }
        
        return ans;
    }
};