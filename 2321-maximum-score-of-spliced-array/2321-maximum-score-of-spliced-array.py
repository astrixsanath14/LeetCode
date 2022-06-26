class Solution:
  def maximumsSplicedArray(self, A, B):
    def kadane(A, B):
        res = cur = 0
        for i in range(len(A)):
            cur = max(0, cur + A[i] - B[i])
            res = max(res, cur)
        return res + sum(B)
    return max(kadane(A, B), kadane(B, A))