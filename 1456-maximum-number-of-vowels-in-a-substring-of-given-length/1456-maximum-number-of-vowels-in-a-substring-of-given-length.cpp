class Solution {
public:
  bool isVowel(char c)
  {
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
  }
  int maxVowels(string s, int k) {
    int count = 0, maxCount = 0, n=s.length();
    for(int i=0;i<n;i++)
    {
      if(isVowel(s[i]))
        count++;
      if(i>=k && isVowel(s[i-k]))
        count--;
      maxCount = max(maxCount, count);
    }
    return maxCount;
  }
};