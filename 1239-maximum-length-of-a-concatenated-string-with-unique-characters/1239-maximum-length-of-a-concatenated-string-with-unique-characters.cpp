class Solution {
public:  
  int hammingWeight(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
  }
  
  int maxLength(vector<int> &bitRep, int pos, int currentSeq)
  {
    if(pos == bitRep.size())
      return hammingWeight(currentSeq);
    int maxLen = 0;
    if(!(currentSeq & bitRep[pos]))
      maxLen = maxLength(bitRep, pos+1, currentSeq | bitRep[pos]);
    return max(maxLen, maxLength(bitRep, pos+1, currentSeq));
  }
  int maxLength(vector<string>& arr) {
    vector<int> bitRep;
    for(string word : arr)
    {
      int n = 0, valid = 1;
      for(char c:word){
        if(n & 1<<(c-'a')){
          valid = 0;
          break;
        }
        n = n | 1<<(c-'a');
      }
      if(valid)
        bitRep.push_back(n);
    }
    int currentSeq = 0, maxLen = 0;
    for(int i=0;i<bitRep.size();i++)
    {
      maxLen = max(maxLen, maxLength(bitRep, i, currentSeq));
    }
    return maxLen;
  }
};