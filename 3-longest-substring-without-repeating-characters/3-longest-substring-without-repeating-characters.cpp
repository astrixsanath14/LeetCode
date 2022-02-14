class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> posTracker;
    int maxLen = 0, first = 0;
    for(int i=0;i<s.length();i++)
    {
      if(!posTracker.count(s[i]) || posTracker[s[i]]<first)
        posTracker[s[i]]= -1;
      if(posTracker[s[i]] != -1)
        first = posTracker[s[i]]+1;
      posTracker[s[i]] = i;
      maxLen = max(maxLen, i-first+1);
      if(s.length() - first <= maxLen)
        return maxLen;
    }
    return maxLen;
  }
};

/*
"abcabcbb"
"bbbbb"
"pwwkew"
"abba"
*/