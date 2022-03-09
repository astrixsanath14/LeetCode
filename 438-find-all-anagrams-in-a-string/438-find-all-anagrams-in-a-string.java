class Solution {
  public List<Integer> findAnagrams(String s, String p) {
    List<Integer> res = new ArrayList();
    int[] freqS = new int[26], freqP = new int[26];
    int matched = 0, n = s.length(), m = p.length();
    if(n < m)
      return res;
    for(int i=0;i<m;i++)
    {
      freqP[p.charAt(i)-'a']++;
      freqS[s.charAt(i)-'a']++;
    }
    
    for(int i=0;i<26;i++)
        matched+=(freqP[i] == freqS[i]  ? 1 : 0);
    
    if(matched == 26)
      res.add(0);
    
    System.out.println(matched);
    for(int i=m;i<n;i++)
    {
      int exitingVal = s.charAt(i-m) - 'a';
      int enteringVal = s.charAt(i) - 'a';
      
      if(freqS[enteringVal] == freqP[enteringVal])
        matched--;
      freqS[enteringVal]++;
      if(freqS[enteringVal] == freqP[enteringVal])
        matched++;
      
      if(freqS[exitingVal] == freqP[exitingVal])
        matched--;
      freqS[exitingVal]--;
      if(freqS[exitingVal] == freqP[exitingVal])
        matched++;
      
      System.out.println(matched);
      if(matched == 26)
        res.add(i-m+1);
    }
    return res;
  }
}