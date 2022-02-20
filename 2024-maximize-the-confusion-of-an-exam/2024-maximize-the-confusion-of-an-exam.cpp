class Solution {
public:
  bool isPosibleConsecutiveAnswers(string &answerKey, int k, int l)
  {
    if(l > answerKey.length())
      return false;
    int tCount = 0;
    for(int i=0;i<l;i++)
      tCount += answerKey[i] == 'T';
    if(tCount <= k || l-tCount <= k)
      return true;
    
    for(int i=l;i<answerKey.length();i++)
    {
      tCount -= answerKey[i-l] == 'T';
      tCount += answerKey[i] == 'T';
      if(tCount <= k || l-tCount <= k)
        return true;
    }
    return false;
  }
  
  int maxConsecutiveAnswers(string answerKey, int k) {
    int left = 1, right = answerKey.length();
    while(left <= right)
    {
      int mid = (left+right)/2;
      bool isPossible = isPosibleConsecutiveAnswers(answerKey, k, mid);
      cout<<"left: "<<left<<" right: "<<right<<" mid: "<<mid<<" isPossible: "<<boolalpha<<isPossible<<"\n";
      if(!isPossible)
      {
        right = mid-1;
      }
      else
      {
        if(!isPosibleConsecutiveAnswers(answerKey, k, mid+1))
          return mid;
        left = mid + 1;
      }
    }
    return 0;
  }
};