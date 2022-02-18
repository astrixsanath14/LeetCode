vector<int> res;

class Solution {
public:
  
  void createNumsSameConsecDiff(int n, int k, int curr) {
    if(n==1){
      res.push_back(curr);
      return;
    }
    int currDigit = curr%10, nextDigitLeft = currDigit-k, nextDigitRight = currDigit+k;
    if(nextDigitLeft>=0)
      createNumsSameConsecDiff(n-1, k, curr*10+nextDigitLeft);
    if(nextDigitRight<=9 && nextDigitRight!=nextDigitLeft)
      createNumsSameConsecDiff(n-1, k, curr*10+nextDigitRight);
  }
    
  vector<int> numsSameConsecDiff(int n, int k) {
    res.clear();
    for(int i=1;i<=9;i++)
      createNumsSameConsecDiff(n, k, i);
    return res;
  }
};