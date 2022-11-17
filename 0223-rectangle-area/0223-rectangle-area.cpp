class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long area1 = (ax1-ax2)*(ay1-ay2);
        long area2 = (bx1-bx2)*(by1-by2);

        int overlappingArea = 0;
        int x1=-1,x2=-1,y1=-1,y2=-1;
        
        x1 = max(bx1,ax1);
        x2 = min(bx2,ax2);
        y1 = max(by1,ay1);
        y2 = min(by2,ay2);
        if(x2-x1>0 && y2>y1)
        {       
            overlappingArea = (x2-x1)*(y2-y1);
        }
        
        return area1+area2-overlappingArea;
    }
};