class Solution 
{
  public int maxDistToClosest(int[] seats) 
  {
    int count = 0, maxCount = Integer.MIN_VALUE;
    boolean isFirstOccupiedSeatPassed = true;
    for(int i=0;i<seats.length ;i++)
    {
      if(seats[i]==1)
      {
        if(isFirstOccupiedSeatPassed && i!=0)
          count *= 2;
        maxCount = Math.max(maxCount, count);
        count = 0;
        isFirstOccupiedSeatPassed = false;
      }
      else
        count++;
    }
    if(count>0)
      maxCount = Math.max(maxCount, 2*count);
    return (maxCount+1)/2;
  }
}