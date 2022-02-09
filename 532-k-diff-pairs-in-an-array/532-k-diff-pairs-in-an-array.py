class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
      c = collections.Counter(nums)
      res = 0
      for i in c:
        if (k==0 and c[i]>1) or (k!=0 and c[i+k] > 0):
          res+=1
      return res