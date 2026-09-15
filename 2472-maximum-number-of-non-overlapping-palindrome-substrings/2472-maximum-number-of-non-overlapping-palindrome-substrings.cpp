class Solution {
private:
    // Helper function to check if substring s[l...r] is a palindrome
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1; // End index of the last chosen non-overlapping palindrome
        
        for (int i = k - 1; i < n; i++) {
            // Option 1: Check palindrome of length k ending at index i
            int start_k = i - k + 1;
            if (start_k > last_end && isPalindrome(s, start_k, i)) {
                count++;
                last_end = i;
                continue;
            }
            
            // Option 2: Check palindrome of length k + 1 ending at index i
            int start_k1 = i - k;
            if (start_k1 > last_end && isPalindrome(s, start_k1, i)) {
                count++;
                last_end = i;
            }
        }
        
        return count;
    }
};