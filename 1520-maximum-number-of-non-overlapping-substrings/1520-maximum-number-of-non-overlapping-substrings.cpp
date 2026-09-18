class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, INT_MAX), last(26, -1);
        
        // Step 1: Precompute first and last occurrences of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }
        
        // Step 2: Find all valid intervals [L, R]
        vector<pair<int, int>> validIntervals;
        
        for (int i = 0; i < 26; i++) {
            if (first[i] == INT_MAX) continue;
            
            int L = first[i];
            int R = last[i];
            bool isValid = true;
            
            // Expand window to include all occurrences of characters within [L, R]
            for (int j = L; j <= R; j++) {
                int c = s[j] - 'a';
                if (first[c] < L) { // Invalid interval if character extends to left of L
                    isValid = false;
                    break;
                }
                R = max(R, last[c]);
            }
            
            if (isValid) {
                validIntervals.push_back({L, R});
            }
        }
        
        // Step 3: Sort valid intervals by their right boundary R
        sort(validIntervals.begin(), validIntervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        // Step 4: Greedy selection of non-overlapping intervals
        vector<string> result;
        int lastEnd = -1;
        
        for (const auto& interval : validIntervals) {
            int L = interval.first;
            int R = interval.second;
            
            if (L > lastEnd) {
                result.push_back(s.substr(L, R - L + 1));
                lastEnd = R;
            }
        }
        
        return result;
    }
};