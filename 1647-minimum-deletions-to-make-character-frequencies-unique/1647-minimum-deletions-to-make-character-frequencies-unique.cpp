class Solution {
public:
  int minDeletions(string s) {
    int freq[26]={0};
    for(char c: s)
      freq[c-'a']++;
    priority_queue<int> maxHeap;
    for(int i=0;i<26;i++)
    {
      if(freq[i] != 0)
        maxHeap.push(freq[i]);
    }
    int deletedCount = 0;
    while(!maxHeap.empty())
    {
      int top = maxHeap.top();
      maxHeap.pop();
      while(top!=0 && !maxHeap.empty() && maxHeap.top() == top)
      {
        deletedCount++;
        maxHeap.pop();
        maxHeap.push(top-1);
      }
    }
    return deletedCount;
  }
};