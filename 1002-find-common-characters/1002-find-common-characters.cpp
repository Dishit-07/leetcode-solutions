class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, 0);
        for (char c : words[0]) {
            minFreq[c - 'a']++;
        }
        
        for (int i = 1; i < words.size(); i++) {
            vector<int> charFreq(26, 0);
            for (char c : words[i]) {
                charFreq[c - 'a']++;
            }
            
            for (int j = 0; j < 26; j++) {
                minFreq[j] = min(minFreq[j], charFreq[j]);
            }
        }
        
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (minFreq[i] > 0) {
                result.push_back(string(1, 'a' + i)); 
                minFreq[i]--;
            }
        }
        
        return result;
    }
};