class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = [-1]
        heights.append(0)
        ans = 0
        for i, height in enumerate(heights):
            while heights[stack[-1]] > height:
                h = heights[stack.pop()] 
                w = i - stack[-1] - 1
                print(h,w)
                print(stack[-1])
                ans = max(ans, h*w)
            stack.append(i)
        heights.pop()
        return ans