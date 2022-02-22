class Solution {
public:
  int titleToNumber(string s) {
    	return accumulate(s.begin(), s.end(), 0, [](const int&a, const char&b){return 26 * a + (b - 'A') + 1;});

  }
};

/*
A - 26^0 * 1
B - 26^0 * 2
AA - 26^1 * 1 + 26^0 * 1 
BA - 26^1 * 2 + 26^0 * 2
AAA - 26^3 * 1 + 26^2 * 1 + 26^0 * 0
*/