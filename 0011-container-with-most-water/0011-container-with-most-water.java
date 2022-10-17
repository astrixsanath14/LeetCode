class Solution {
    public int maxArea(int[] height) {
        int leftContainer = 0;
        int rightContainer = height.length - 1;
        int maxArea = 0;
        while(leftContainer < rightContainer)
        {
            maxArea = Math.max(maxArea, Math.min(height[leftContainer], height[rightContainer]) * (rightContainer - leftContainer));
            if(height[rightContainer] < height[leftContainer])
            {
                rightContainer--;
            }
            else
            {
                leftContainer++;
            }
        }
        return maxArea;
    }
}