bool isWorkableSpeed(vector<int>& piles, int speed, int maxHours)
{
  int timeTaken = 0;
  for(int bananaCount : piles)
  {
    timeTaken += ceil((double)bananaCount/(double)speed);
  }
  // cout<<"timeTaken: "<<timeTaken<<endl;
  return timeTaken <= maxHours;
}

class Solution 
{
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
      int minBananaSpeed = 1;
      int maxBananaSpeed = *max_element(piles.begin(), piles.end());
      while(minBananaSpeed<maxBananaSpeed)
      {
        int mid = (minBananaSpeed + maxBananaSpeed)/2;
        cout<<minBananaSpeed<<" "<<mid<<" "<<maxBananaSpeed<<endl;
        if(isWorkableSpeed(piles, mid, h))
        {
          // cout<<"Eligible "<<mid<<endl;
          maxBananaSpeed = mid;
        }
        else
        {
          minBananaSpeed = mid;
        }
        if(minBananaSpeed == maxBananaSpeed - 1)
        {
          break;
        }
      }
      if(minBananaSpeed!=maxBananaSpeed)
      {
        if(isWorkableSpeed(piles, minBananaSpeed, h))
        {
          return minBananaSpeed;
        }
        else
        {
          return maxBananaSpeed;
        }
      }
      else
      {
        return minBananaSpeed; 
      }
    }
};