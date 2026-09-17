class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // min_len[i] stores the minimum length of a valid target subarray ending at or before index i
        vector<int> min_len(n, 1e9); 
        
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1; // Base case for prefix sum
        
        int curr_sum = 0;
        int result = 1e9;
        
        for (int i = 0; i < n; i++) {
            curr_sum += arr[i];
            prefixMap[curr_sum] = i;
            
            // Maintain min_len from previous index
            if (i > 0) {
                min_len[i] = min_len[i - 1];
            }
            
            // Check if there is a subarray ending at index i with sum equal to target
            if (prefixMap.count(curr_sum - target)) {
                int start_idx = prefixMap[curr_sum - target];
                int current_length = i - start_idx;
                
                // If there was a valid non-overlapping subarray before start_idx
                if (start_idx >= 0 && min_len[start_idx] != 1e9) {
                    result = min(result, current_length + min_len[start_idx]);
                }
                
                // Update min_len[i] with the shortest valid subarray found so far
                min_len[i] = min(min_len[i], current_length);
            }
        }
        
        return result >= 1e9 ? -1 : result;
    }
};