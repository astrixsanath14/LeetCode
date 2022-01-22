class Solution 
{
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
      int count = arr.size();
      vector<int> prefixMax(count);
      prefixMax[0] = arr[0];
      for(int i=1;i<count;i++){
        prefixMax[i] = max(arr[i],prefixMax[i-1]);
      }
      int chunkCount = 0;
      for(int i=0;i<count;i++)
      {
        chunkCount += i==prefixMax[i];
      }
      return chunkCount;
    }
};