class Solution {
public:
  vector<int> findAnagrams(string s, string p) 
  {
    int k = p.size();
    map<char,int> pMap, sMap;
    vector<int> res;
    for(int i=0;i<26;i++)
    {
      pMap['a'+i]=0;
      sMap['a'+i]=0;
    }
    for(int i=0;i<s.size();i++)
    {
      sMap[s[i]]++;
      if(i<k)
        pMap[p[i]]++;
      else
        sMap[s[i-k]]--;
      if(i>=k-1 && pMap == sMap)
        res.push_back(i-k+1);
    }
    return res;
  }
};