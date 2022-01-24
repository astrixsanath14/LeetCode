bool isCaps(char c)
{
  return c>='A' && c<='Z';
}

class Solution {
public:
  bool detectCapitalUse(string word) 
  {
    int capsCount = word.size();
    for(int i=0;i<word.size();i++)
    {
      capsCount-=!isCaps(word[i]);
    }
    return capsCount==word.size() || capsCount == 0 || (capsCount == 1 && isCaps(word[0]));
  }
};