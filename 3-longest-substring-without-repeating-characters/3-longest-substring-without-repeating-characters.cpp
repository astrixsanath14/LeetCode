class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char,int> posTracker;
    int maxLen = 0, counter=0, first = 0;
    for(int i=0;i<s.length();i++)
    {
      if(!posTracker.count(s[i]))
        posTracker[s[i]]= -1;
      counter++;
      if(posTracker[s[i]] != -1)
      {
        counter -= posTracker[s[i]] - first + 1;
        first = posTracker[s[i]]+1;
        for (auto character : posTracker)
        {
          if(character.second < first){
            posTracker[character.first] = -1;
          }
        }
      }
      posTracker[s[i]] = i;
      maxLen = max(maxLen, counter);
      // cout<<i<<" "<<maxLen<<" "<<first<<" "<<counter<<"\n";
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