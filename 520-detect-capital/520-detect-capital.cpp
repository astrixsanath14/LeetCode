bool isCaps(char c)
{
  return c>='A' && c<='Z';
}

class Solution {
public:
  bool detectCapitalUse(string word) 
  {
    int capsCount = 0,len = word.size();
    for(int i=0;i<len;i++)
    {
      capsCount+=isCaps(word[i]);
    }
    return capsCount==len || capsCount == 0 || (capsCount == 1 && isCaps(word[0]));
  }
};