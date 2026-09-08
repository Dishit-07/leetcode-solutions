

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Base case: empty array
        if (nums.empty()) return 0;
        
        int k = 1; // Index where the next unique element will be placed
        
        for (int i = 1; i < nums.size(); i++) {
            // Found a new unique element
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};