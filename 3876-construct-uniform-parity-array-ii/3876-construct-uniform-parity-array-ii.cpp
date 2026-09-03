class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = nums1[0];
        bool hasOdd = false;
        
        for (int num : nums1) {
            minVal = min(minVal, num);
            if (num % 2 != 0) {
                hasOdd = true;
            }
        }
        
        // Case 1: Agar koi odd element hi nahi hai, saare pehle se even hain
        if (!hasOdd) return true;
        
        // Case 2: Agar minimum element odd hai, hum sabhi ko even ya odd bana sakte hain
        if (minVal % 2 != 0) return true;
        
        // Baaki sabhi cases mei impossible hai
        return false;
    }
};