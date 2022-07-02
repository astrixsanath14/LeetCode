class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int maxHeight = horizontalCuts[0], maxWidth = verticalCuts[0];
    
    for(int i = 1; i<horizontalCuts.size(); i++)
    {
      if(horizontalCuts[i] - horizontalCuts[i-1] > maxHeight)
        maxHeight = horizontalCuts[i] - horizontalCuts[i-1];
    }
    maxHeight = max(maxHeight, h - horizontalCuts[horizontalCuts.size() - 1]);
    
    for(int i = 1; i<verticalCuts.size(); i++)
    {
      if(verticalCuts[i] - verticalCuts[i-1] > maxWidth)
        maxWidth = verticalCuts[i] - verticalCuts[i-1];
    }
    maxWidth  = max(maxWidth, w - verticalCuts[verticalCuts.size() - 1]);
    
    return (1l * maxHeight * maxWidth % (int)(1E9+7));
  }
};