class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store {value, index}
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Agar complement pehle se map mei hai, toh hume pair mil gaya!
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            
            // Nahi milne par current element aur uska index map mei daal do
            mp[nums[i]] = i;
        }
        
        return {};
    }
};