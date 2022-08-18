class Solution {
public:
  int minSetSize(vector<int>& arr) {
    map<int,int> freq;
    for(int val:arr)
    {
      freq[val]++;
    }
    int result = 0, n = arr.size();
    vector<pair<int,int>> elements(freq.size());
    int counter = 0;
    for(auto mp : freq)
    {
      elements[counter++] = {mp.first, mp.second};
    }
    sort(elements.begin(), elements.end(), 
    [](const pair<int,int> &a, const pair<int,int> &b) -> bool
    { 
        return a.second > b.second; 
    });
    
    for(auto element : elements)
    {
      if(n > arr.size()/2)
      {
        result++;
        n-=element.second;
      }
      else
        break;
    }
    return result;
  }
};