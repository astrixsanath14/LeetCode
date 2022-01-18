class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int flowerbedSize = flowerbed.size();
      for(int i = 0;i<flowerbedSize;i++)
      {
        int left = i == 0 ? 0 : flowerbed[i-1];
        int right = i == flowerbedSize - 1 ? 0 : flowerbed[i+1];
        if(n && !flowerbed[i] && !left && !right)
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