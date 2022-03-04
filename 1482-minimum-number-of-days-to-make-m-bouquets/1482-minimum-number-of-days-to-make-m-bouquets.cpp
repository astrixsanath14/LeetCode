bool hasMBouquets(vector<int>& bloomDay, int m, int k, int day)
{
  int n = bloomDay.size(), noOfBlooms = 0, i=0, bouquetCount = 0;
  for(int reqDay:bloomDay)
  {
    if(reqDay <= day)
    {
      noOfBlooms++;
      if(noOfBlooms == k)
      {
        bouquetCount++;
        noOfBlooms = 0;
      }
    }
    else
      noOfBlooms = 0;
  }
  return bouquetCount >= m;
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      int minBloomDay = INT_MAX, maxBloomDay = INT_MIN;
      if(m*k>bloomDay.size())
      return -1;
      for(int day:bloomDay)
      {
        minBloomDay = min(minBloomDay, day);
        maxBloomDay = max(maxBloomDay, day);
      }
      while(minBloomDay <= maxBloomDay)
      {
        int midBloomDay = (minBloomDay + maxBloomDay)/2;
        if(hasMBouquets(bloomDay, m, k, midBloomDay))
        {
          if(!hasMBouquets(bloomDay, m, k, midBloomDay-1))
            return midBloomDay;
          maxBloomDay = midBloomDay-1;
        }
        else
        {
          minBloomDay = midBloomDay+1;
        }
      }
      return -1;
    }
};