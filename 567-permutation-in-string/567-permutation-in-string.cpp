class Solution {
public:
  bool hasKey(unordered_map<char, int> m, char key)
  {
      return m.count(key) != 0;
  }
  bool checkInclusion(string s1, string s2) {
    int k=0, matched=0, s1Len = s1.size();
    unordered_map<char,int> counter1,counter2;
    for(int i=0;i<s1Len;i++)
    {
      if(!hasKey(counter1, s1[i])){
        counter1[s1[i]] = 0;
        counter2[s1[i]] = 0;
        k++;
      }
      counter1[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
      if(i>=s1Len)
      {
        if(hasKey(counter2, s2[i-s1Len]))
        {
          if(counter1[s2[i-s1Len]] == counter2[s2[i-s1Len]])
            matched--;
          counter2[s2[i-s1Len]]--;
        }
      }
      if(hasKey(counter2,s2[i]))
      {
        counter2[s2[i]]++;
        if(counter1[s2[i]] == counter2[s2[i]])
          matched++;
        if(matched == k)
          return true;
      }
    }
    return false;
  }
};