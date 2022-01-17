bool isMapKeyExists(map<char,string> map, char key)
{
  return map.find(key) != map.end();
}

bool isMapKeyExists(map<string,char> map, string key)
{
  return map.find(key) != map.end();
}

class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
      bool isPatternMatched = true;
      map<char,string> patternCharVsWordMap;
      map<string,char> patternWordVsCharMap;
      istringstream ss(s);
      string word;
      int i = 0;
      int patternSize = pattern.size();
      while (ss >> word) 
      {
        if(i>=patternSize)
        {
          isPatternMatched = false;
          break;
        }
        char c = pattern[i];
        if(isMapKeyExists(patternCharVsWordMap, c))
        {
          if(patternCharVsWordMap[c] != word)
          {
            isPatternMatched = false;
            break;
          }
        }
        else
        {
          patternCharVsWordMap[c] = word;
        }
        if(isMapKeyExists(patternWordVsCharMap,word))
        {
          if(patternWordVsCharMap[word] != c)
          {
            isPatternMatched = false;
            break;
          }
        }
        else
        {
          patternWordVsCharMap[word] = c;
        }
        i++;
      }
      isPatternMatched = i!=patternSize ? false : isPatternMatched;
      return isPatternMatched;
    }
};