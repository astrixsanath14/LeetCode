class Solution {
public:
  vector<int> avoidFlood(vector<int>& rains) {
    set<int> zeros;
    map<int,int> floods;
    map<int,int> lastLocations;
    
    vector<int> ans(rains.size());
    for(int i=0;i<rains.size();i++){
      if(rains[i]>0)
      {
        floods[rains[i]] = floods[rains[i]]+1;
        if(floods[rains[i]] >1)
        {
          int lastInd = lastLocations[rains[i]];
          //flood
          if(zeros.size() == 0)
            return vector<int>(0);
          bool foundZero = false;
          for(int fillInd : zeros)
          {
            if(lastInd<fillInd)
            {
              ans[fillInd] = rains[i]; 
              zeros.erase(fillInd);
              foundZero = true;
              break;
            }
          }
          if(!foundZero)
            return vector<int>(0);
          floods[rains[i]]--;
        }
        ans[i] = -1;
        lastLocations[rains[i]] = i;
      }
      else{
        zeros.insert(i);
        ans[i] = 1;
      }
    }
    return ans;
  }
};