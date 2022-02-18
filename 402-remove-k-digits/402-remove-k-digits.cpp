class Solution {
public:
  string removeKdigits(string num, int k) {
    stack<char> digits;
    for(char n : num)
    {
      while(k && !digits.empty() && n<digits.top())
      {
        digits.pop();
        k--;
      }
      digits.push(n);
      if(digits.size()==1 && n=='0')
        digits.pop();
    }
    while(k && !digits.empty())
    {
      digits.pop();
      k--;
    }
    num="";
    while(!digits.empty())
    {
      num = digits.top() + num;
      digits.pop();
    }
    return num==""?"0":num;
  }
};