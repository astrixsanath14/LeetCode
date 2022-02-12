class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> set = new HashSet<>(wordList);
        if(!set.contains(endWord)) 
          return 0;
        
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        
        int changes = 1;
        
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                String word = queue.poll();
                if(word.equals(endWord)) 
                  return changes;
              
                for(int j = 0; j < word.length(); j++){
                  char arr[] = word.toCharArray();
                    for(arr[j] = 'a'; arr[j] <= 'z'; arr[j]++){
                        String str = new String(arr);
                        if(set.contains(str)){
                            queue.add(str);
                            set.remove(str);
                        }
                    }
                }
            }
            ++changes;
        }
        return 0;
    }
}