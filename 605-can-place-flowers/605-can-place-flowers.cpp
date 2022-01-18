class Solution {
public:
bool canPlaceFlowers(vector<int>& flowerbed, int n) {

    int len=flowerbed.size(), i=0, count=0; 
    if(n==0)
        return true;
	// if flowerbed has 1 element only
    if(len==1)
        return (flowerbed[i]==1 ? false:true);
		
     // to check if flower can be planted in first plot
    if(flowerbed[i]==0) {
        if(flowerbed[i+1]==0) {
            count++;
            flowerbed[i]=1;
        }
    }
    i++;
    
    while(i<len-1) {
        int flag=0;
        if(flowerbed[i]==0) {
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0) {
                count++;
                flowerbed[i]=1;
                i+=2;
                flag=1;
            }
        }
        
        if(flag==0)
          i++;
    }
    
	// to check if flower can be planted in the last plot
    if(flowerbed[len-1]==0 && flowerbed[len-2]==0) {
        count++;
        flowerbed[len-1]=1;
    }
    if(count>=n)
        return true;
return false;
 }
};