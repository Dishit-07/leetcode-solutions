class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> freq(256,0);
        int left = 0,right = 0;
        int maxLength = 0;
        while(right < s.length()){
            char curr = s[right];
            freq[curr]++;
            while(freq[curr] > 1){
                freq[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right-left+1);
            right++; 
        }
        return maxLength;
    }
};