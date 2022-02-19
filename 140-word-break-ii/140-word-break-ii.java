class Solution {
  public void solve(String s, int startIdx, int currIdx, String sentence, Set<String> wordDict, List<String> res)
  {
    if(currIdx == s.length())
    {
      if(startIdx < currIdx)
      {
        String currWord = s.substring(startIdx, currIdx);
        if(wordDict.contains(currWord))
        {
          if(sentence!="")
            sentence += " ";
          sentence += currWord;
        }
        else
          return;
      }
      res.add(sentence);
      return;
    }
    String currWord = s.substring(startIdx, currIdx);
    if(wordDict.contains(currWord))
    {
      String nextSentence = sentence;
      if(nextSentence!="")
        nextSentence += " ";
      nextSentence += currWord;
      solve(s, currIdx, currIdx+1, nextSentence, wordDict, res);
    }
    solve(s, startIdx, currIdx+1, sentence, wordDict, res);
  }
  
  public List<String> wordBreak(String s, List<String> wordDict) {
    List<String> res = new ArrayList();
    Set<String> mp = new HashSet(wordDict);
    solve(s, 0, 0, "", mp, res);
    return res;
  }
}