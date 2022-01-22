void printVectorContents(vector<int>& arr)
{
  for(int val: arr)
  {
    cout<<val<<" ";
  }
  cout<<endl;
}

class Solution 
{
public:
    int trap(vector<int>& pillarHeights) 
    {
      int pillarCount = pillarHeights.size();
      cout<<"pillarCount: " << pillarCount<<endl;
      vector<int> prefixMax(pillarCount);
      vector<int> suffixMax(pillarCount);
      prefixMax[0] = pillarHeights[0];
      suffixMax[pillarCount - 1] = pillarHeights[pillarCount - 1];
      for(int i=1;i<pillarCount;i++)
      {
        prefixMax[i] = max(pillarHeights[i],prefixMax[i-1]);
        suffixMax[pillarCount - i - 1] = max(pillarHeights[pillarCount - i - 1],suffixMax[pillarCount - i]);
      }
      
      cout<<"\nSuffix Max Array: \n";
      printVectorContents(suffixMax);
      cout<<"\nPrefix Max Array: \n";
      printVectorContents(prefixMax);
      
      int totalWaterAccumulated = 0;
      for(int i=1;i<pillarCount-1;i++)
      {
        int shortestBoundaryPillar = min(prefixMax[i-1],suffixMax[i+1]);
        if(shortestBoundaryPillar > pillarHeights[i])
          totalWaterAccumulated += shortestBoundaryPillar - pillarHeights[i];
      }
      return totalWaterAccumulated;
    }
};