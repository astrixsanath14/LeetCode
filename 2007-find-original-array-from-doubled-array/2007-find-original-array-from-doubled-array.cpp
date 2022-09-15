class Solution {
public:
  vector<int> findOriginalArray(vector<int>& changed) {
    vector<int> orginal;
    int len = changed.size();
    if(len%2)
      return vector<int>();
    sort(changed.begin(), changed.end());
    int ind = 0, doubledInd = 1;;
    while(ind < len)
    {
      if(ind>= doubledInd)
        doubledInd = ind+1;
      if(doubledInd >= len)
        return vector<int>();
      
      while(changed[ind]*2 != changed[doubledInd])
      {
        doubledInd++;
        if(doubledInd >= len)
          break;
      }
      if(doubledInd >= len)
        return vector<int>();
      
      orginal.push_back(changed[ind]);
      changed[ind] = -1;
      changed[doubledInd] = -1; 
      while(changed[ind] == -1)
      {
        ind++;
        if(ind >= len)
          break;
      }
    }
    return orginal;
  }
};