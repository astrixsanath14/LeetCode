class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
      print(nums)
      nums.sort()
      nums = [-2] + nums + [1000002]
      n=len(nums)
      lonelyNums = []
      for i in range(1,n-1):
        if nums[i-1] < nums[i]-1 and nums[i+1] > nums[i]+1:
          lonelyNums += [nums[i]]
      return lonelyNums