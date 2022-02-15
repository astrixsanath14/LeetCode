
class Solution {
  public void reverseString(char[] s, int ind)
  {
    if(!(ind < s.length/2))
      return;
    char i=s[ind];
    s[ind] = s[s.length-ind-1];
    s[s.length-ind-1] = i;
    reverseString(s, ind+1);
  }
  public void reverseString(char[] s) {
    reverseString(s, 0);
  }
}