class Solution {
public:
    int mySqrt(int x) {
        // Base Cases
        if (x == 0 || x == 1) return x;
        
        int left = 1, right = x;
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Overflow se bachne ke liye comparison: mid <= x / mid
            if (mid <= x / mid) {
                ans = mid;        // Store potential answer
                left = mid + 1;   // Check right half for larger values
            } else {
                right = mid - 1;  // Check left half
            }
        }
        
        return ans;
    }
};