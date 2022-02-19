class Solution {
public:
  
  void solve(string s, string currPath, string currWord, unordered_map<string, bool>& wordDict, vector<string>& res)
  {
    if(s == "")
    {
      if(wordDict[currWord])
      {
        currPath += currPath == "" ? currWord : " " + currWord;
        res.push_back(currPath);
      }
      return;
    }
    currWord += s[0];
    s.erase(0,1);
    if(wordDict[currWord])
    {
      solve(s, (currPath == "") ? currWord : (currPath + " " + currWord), "", wordDict, res);
    }
    solve(s, currPath, currWord, wordDict, res);
  }
  
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,bool> mp;
    for(string word : wordDict)
    {
      mp[word] = true;
    }
    vector<string> res;
    solve(s, "", "", mp, res);
    return res;
  }
};