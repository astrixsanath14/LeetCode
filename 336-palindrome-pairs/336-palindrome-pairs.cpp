class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int wordSize = words.size();
        vector<string> reversedWords(wordSize);
        for (int i = 0; i < wordSize; i++) {
            string s = words[i];
            std::reverse(s.begin(), s.end());
            reversedWords[i] = s;
            reversedWordToIndex[reversedWords[i]] = i;
        }
        
        // "" matches with every word if the word is palindrome
        const auto itEmpty = reversedWordToIndex.find("");
        if (itEmpty != reversedWordToIndex.end()) {
            const int emptyIndex = itEmpty->second;
            for (int i = 0; i < wordSize; i++) {
                if (i == emptyIndex) continue;
                const string &word = words[i];
                const int wordLen = word.length();
                if (!isPalindrome(word, 0, wordLen - 1)) continue;
                results.emplace_back(vector<int>{emptyIndex, i});
                results.emplace_back(vector<int>{i, emptyIndex});
            }
        }
        
        for (int i = 0; i < wordSize; i++) {
            const string &word = words[i];
            const int wordLen = word.length();
            
            // Check if substr(word, sublen) from left == reversedWord
            for (int sublen = 1; sublen < wordLen; sublen++) {
                const int matchIndex = findLeftSubstrMatchIndex(word, sublen);
                if (matchIndex < 0 || matchIndex == i) continue;
                results.emplace_back(vector<int>{i, matchIndex});
            }
            
            // Check if substr(word, sublen) from right == reversedWord
            for (int sublen = 1; sublen < wordLen; sublen++) {
                const int matchIndex = findRightSubstrMatchIndex(word, sublen);
                if (matchIndex < 0 || matchIndex == i) continue;
                results.emplace_back(vector<int>{matchIndex, i});
            }
            
            // Check if word == reversedWord
            const int matchIndex = findLeftSubstrMatchIndex(word, wordLen);
            if (matchIndex < 0 || matchIndex >= i) continue; // matchIndex >= i is to avoid duplicate pairs, matchIndex <= i would also be okay
            results.emplace_back(vector<int>{i, matchIndex});
            results.emplace_back(vector<int>{matchIndex, i});
        }
        return results;
    }
    
    // words=["batx", "tab"]
    // reversed=["xtab", "bat"]
    // substr(word="batx", sublen=3) = "bat"
    int findLeftSubstrMatchIndex(const string &word, const int sublen) {
        const string_view part(word.c_str(), sublen);
        const auto it = reversedWordToIndex.find(part);
        if (it == reversedWordToIndex.end()) return -1;
        if (isPalindrome(word, sublen, word.length() - 1)) return it->second;
        return -1;
    }
    
    // words=["tabx", "bat"]
    // reversed=["xtab", "tab"]
    // substr(word="xtab", sublen=3) = "tab"
    int findRightSubstrMatchIndex(const string &word, const int sublen) {
        const string_view part(word.c_str() + word.length() - sublen);
        const auto it = reversedWordToIndex.find(part);
        if (it == reversedWordToIndex.end()) return -1;
        if (isPalindrome(word, 0, word.length() - sublen - 1)) return it->second;
        return -1;
    }
    
    bool isPalindrome(const string &word, int left, int right) {
        while (left < right && word[left] == word[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
    
    unordered_map<string_view, int> reversedWordToIndex;
    vector<vector<int>> results;
};