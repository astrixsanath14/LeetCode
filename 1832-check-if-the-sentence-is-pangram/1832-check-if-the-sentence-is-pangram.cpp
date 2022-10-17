class Solution {
public:
    bool checkIfPangram(string sentence) {
        int chars[26] = {0}, sum = 0;
        for(char c:sentence)
        {
            sum += chars[c-'a']==0;
            chars[c-'a']++;
        }
        return sum == 26;
    }
};