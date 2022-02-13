class Solution {
public:
  map<pair<int,int>, bool> mem;
  
  bool validate(string s, int pos, int counter)
  {
    pair<int,int> cur = pair<int,int>(pos, counter);
    if(mem.count(cur))
      return mem[cur];
    if(counter < 0)
      return false;
    if(pos==s.length())
      return counter==0;
    bool result = false;
    if(s[pos] == '*')
    {
      //No paranthesis
      result = result | validate(s, pos+1, counter);
      //Opening paranthesis
      result = result | validate(s, pos+1, counter+1);
      //Closing paranthesis
      result = result | validate(s, pos+1, counter-1);
    }
    else
    {
      if(s[pos] == '(')
        counter++;
      else
        counter--;
      result = validate(s,pos+1,counter);
    }
    mem[cur] = result;
    return result;
  }
  
  bool checkValidString(string s) {
    return validate(s, 0, 0);
  }
};