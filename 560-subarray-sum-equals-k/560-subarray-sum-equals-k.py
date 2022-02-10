class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans, n = 0, len(nums)
        preSum = 0
        dic = {}
        dic[0] = 1
        for i in nums:
            preSum += i
            if preSum-k in dic:
                ans+=dic[preSum-k]
            dic[preSum] = dic.get(preSum,0) + 1 
        return ans