class Solution {
public:
    char findTheDifference(string s, string t) 
    {
      long diff = 0;
      for(int i=0;i<s.size();i++)
        diff+=t[i]-s[i];
          return diff + t[t.size()-1];
    }
};