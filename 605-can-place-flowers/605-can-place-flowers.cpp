class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int flowerbedSize = flowerbed.size();
      if(flowerbedSize == 1)
      {
        return n-(flowerbed[0]?0:1) <= 0;
      }
      int prev=0;
      int count=0;
      for(int cur:flowerbed)
      {
        if(cur)
          {
           if(prev)
            {
             count--;
            }
          else
          {
            prev=1;
          }
          }
          else
          {
            if(prev)
            {
              prev = 0;
            }
            else
            {
              prev = 1;
              count++;
            }
          }
      }
      return count>=n;
    }
};