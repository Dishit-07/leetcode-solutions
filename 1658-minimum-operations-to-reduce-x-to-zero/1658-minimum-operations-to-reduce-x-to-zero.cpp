class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int target = totalSum - x;
        if (target == 0) return nums.size();
        if (target < 0) return -1;
        
        int n = nums.size();
        int maxLen = -1;
        int currentSum = 0;
        int left = 0;
        
        // Sliding Window to find longest subarray with sum == target
        for (int right = 0; right < n; right++) {
            currentSum += nums[right];
            
            // Shrink window if sum exceeds target
            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : n - maxLen;
    }
};