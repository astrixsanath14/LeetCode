class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
      bool up=true;
      int m=-1,size=arr.size();
      if(size<3)
        return false;
      for(int i=1;i<size;i++)
      {
        if(arr[i] > arr[i-1])
        {
          if(!up)
            return false;
          if(m==-1)
            m=0;
        }
        else if(arr[i] < arr[i-1])
        {
          if(!m)
          {
            if(!up)
              return false;
            m=i;
            up=false; 
          }
          else if(m==-1)
            return false;
        }
        else
          return false;
      }
      return !up;
    }
};