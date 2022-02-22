class Solution {
public:
  int titleToNumber(string columnTitle) {
    long long res=0, offset = 'A'-1, l = columnTitle.length(), charCount = 26;
    for(int i=0;i<l;i++)
      res += pow(charCount, i) * (columnTitle[l-i-1] - offset);
    return res;
  }
};

/*
A - 26^0 * 1
B - 26^0 * 2
AA - 26^1 * 1 + 26^0 * 1 
BA - 26^1 * 2 + 26^0 * 2
AAA - 26^3 * 1 + 26^2 * 1 + 26^0 * 0
*/