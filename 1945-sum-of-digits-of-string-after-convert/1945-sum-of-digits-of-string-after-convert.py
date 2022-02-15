class Solution:
  def getLucky(self, s: str, k: int) -> int:
    nums = list(map(int,''.join([str(ord(i)-96) for i in s])))
    for i in range(k-1):
      nums = list(map(int,str(sum(nums))))
    return sum(nums)