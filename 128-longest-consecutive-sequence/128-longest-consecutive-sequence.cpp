class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    set<int> uniqueNums(nums.begin(), nums.end());
    int best = 0;
    for(int num : uniqueNums)
    {
      const bool isPartOfAnotherSequence = uniqueNums.find(num-1) != uniqueNums.end();
      if(!isPartOfAnotherSequence)
      {
        int next = num+1;
        int localBest = 1;
        while(uniqueNums.find(next) != uniqueNums.end())
        {
          next++;
          localBest++;
        }
        best = max(best, localBest);
      }
    }
    return best;
  }
};