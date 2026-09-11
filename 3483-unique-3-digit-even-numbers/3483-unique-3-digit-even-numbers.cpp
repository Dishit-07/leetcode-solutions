class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }
        
        int count = 0;
        
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;
            
            vector<int> currentFreq(10, 0);
            currentFreq[d1]++;
            currentFreq[d2]++;
            currentFreq[d3]++;
            
            bool possible = true;
            for (int i = 0; i < 10; i++) {
                if (currentFreq[i] > freq[i]) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                count++;
            }
        }
        
        return count; // Returns int
    }
};