#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Precompute suffix min
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        
        int currentPrefixMax = nums[0];
        for (int i = 0; i < n; i++) {
            currentPrefixMax = max(currentPrefixMax, nums[i]);
            
            if (currentPrefixMax - suffixMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};