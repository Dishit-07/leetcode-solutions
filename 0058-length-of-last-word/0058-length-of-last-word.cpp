class Solution {
public:
    int lengthOfLastWord(string s) {
        return distance(find_if(s.rbegin(), s.rend(), ::isalnum), find_if_not(find_if(s.rbegin(), s.rend(), ::isalnum), s.rend(), ::isalnum));
    }
};