class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        for(int i=n-1;i>0;i--)
        {
            int j = 0;
            while(j<i && height[j]<height[i])
            {
                j++;
            }
            if(j!=i)
            {
                maxArea = max(maxArea, height[i] * (i-j));  
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int j = n-1;
            while(j>i && height[j]<height[i])
            {
                j--;
            }
            if(j!=i)
            {
                maxArea = max(maxArea, height[i] * (j-i));  
            }
        }
        return maxArea;
    }
};