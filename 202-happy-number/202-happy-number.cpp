class Solution {
  map<int, bool> checked;
  int getSumOfSquares(int n)
  {
    int sum=0;
    while(n){
      sum+=(n%10)*(n%10);
     n/=10;   
    }
    return sum;
  }
  
  bool checkIfHappy(int n)
  {
    if(n==1)
      return true;
    if(checked[n])
      return false;
    checked[n] = true;
    return checkIfHappy(getSumOfSquares(n));
  }
public:
  bool isHappy(int n) {
    checked.clear();
    return checkIfHappy(n);
  }
};