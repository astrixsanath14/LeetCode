class Node
{
  Node* children[26];
  
  public:
  
  bool isWord;
  void insertLetter(int letter)
  {
    children[letter - 'a'] = new Node();
  }
  
  bool isLetterPresent(int letter)
  {
    return children[letter - 'a'] != NULL;
  }
  
  Node* getNextLetter(int currLetter)
  {
    return children[currLetter - 'a'];
  }
};

class Trie 
{
  Node* root;
    public :
    Trie() 
    {
      root = new Node();
    }
    
    void insert(string word) 
    {
      Node* temp=root;
      for(char c : word)
      {
        if(!temp->isLetterPresent(c))
        {
          temp->insertLetter(c);
        }
        temp = temp->getNextLetter(c);
      }
      temp->isWord = true;
    }
    
    bool search(string word) 
    {
      Node* temp=root;
      for(char c:word)
      {
        if(!temp->isLetterPresent(c))
        {
          return false;
        }
        temp = temp->getNextLetter(c);
      }
      return temp->isWord;
    }
    
    bool startsWith(string prefix) 
    {
      Node* temp=root;
      for(char c:prefix)
      {
        if(!temp->isLetterPresent(c))
        {
          return false;
        }
        temp = temp->getNextLetter(c);
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */