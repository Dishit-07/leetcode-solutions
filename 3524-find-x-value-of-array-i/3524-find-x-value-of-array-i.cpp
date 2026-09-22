class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        
        // dp[x] stores count of valid subarrays ending at the previous index with product % k == x
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int current_mod = num % k;

            // 1. Single element subarray starting and ending at current element
            next_dp[current_mod]++;

            // 2. Extend all previous subarrays ending at (i - 1)
            for (int prev_rem = 0; prev_rem < k; prev_rem++) {
                if (dp[prev_rem] > 0) {
                    int new_rem = (1LL * prev_rem * current_mod) % k;
                    next_dp[new_rem] += dp[prev_rem];
                }
            }

            // 3. Accumulate current DP state into global result array
            for (int rem = 0; rem < k; rem++) {
                result[rem] += next_dp[rem];
            }

            // Move to next state
            dp = move(next_dp);
        }

        return result;
    }
};