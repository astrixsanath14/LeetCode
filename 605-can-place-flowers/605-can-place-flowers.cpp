class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      flowerbed.insert(flowerbed.begin(), 0);
      flowerbed.push_back(0);
      for(int i = 1;i<flowerbed.size()-1;i++)
      {
        if(!flowerbed[i] && !flowerbed[i-1] && !flowerbed[i+1] && n)
        {
          flowerbed[i] = 1;
          n--;
        }
        if(!n)
          break;
        }
      return n==0;
    }
};