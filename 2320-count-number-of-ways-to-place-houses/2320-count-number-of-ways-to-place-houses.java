#define MOD (int)(1E9+7) 
class Solution {
public:
    int countHousePlacements(int n) {
      int houses = 1, spaces = 1;
      long long total = houses + spaces;
      for(int i=2;i<=n;i++)
      {
        houses = spaces;
        spaces = total;
        total = (houses + spaces)%MOD;
      }
      return (total*total)%MOD;
    }
};