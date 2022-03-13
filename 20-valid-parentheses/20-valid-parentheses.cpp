class Solution {
public:
  bool isValid(string s) {
    map<char,char> closing;
    closing[')'] = '(';
    closing[']'] = '[';
    closing['}'] = '{';
    int stack[s.length()],ind=-1;
    for(char c:s)
    {
      // cout<<ind<<" "<<c<<" ";
      // if(ind>=0)
      //   cout<<stack[ind];
      // cout<<"\n";
      if(c == '(' || c == '{' || c == '[')
        stack[++ind] = c;
      else if(ind==-1 || (char)stack[ind--] != closing[c])
        return false;
    }
    return ind==-1;
  }
};