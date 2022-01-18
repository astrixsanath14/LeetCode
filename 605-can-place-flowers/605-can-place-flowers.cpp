class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int flowerbedSize = flowerbed.size();
      if(flowerbedSize == 1)
      {
        return n-(flowerbed[0]?0:1) <= 0;
      }
      for(int i = 0;i<flowerbedSize;i++)
      {
        if(n && !flowerbed[i])
        {
          if(i == 0)
          {
            if(!flowerbed[i+1]){
              n--;
              flowerbed[i]=1;
            }
          }
          else if(i==flowerbedSize - 1)
          {
            if(!flowerbed[i-1]){
              n--;
              flowerbed[i]=1;
            }
          }
          else if(!flowerbed[i-1] && !flowerbed[i+1])
          {
            n--;
            flowerbed[i]=1;
          }
        }
        if(!n)
          return true;
        }
      return false;
    }
};