#include <bits/stdc++.h>
using namespace std;
  
const int ALPHABET_SIZE = 26;
  
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
  
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    int prefixCount;
};
  
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
  
    pNode->isEndOfWord = false;
    pNode->prefixCount = 0;
  
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
  
    return pNode;
}
  

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
  
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
  
        pCrawl = pCrawl->children[index];
    }
  
    return (pCrawl->isEndOfWord);
}


// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
  
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
  
      pCrawl = pCrawl->children[index];
      pCrawl->prefixCount++;
        
    }
  
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

class Solution {
public:
  vector<int> solve(TrieNode *root, vector<string>& words)
  {
    vector<int> result(words.size());
    int count = 0;
    for(string word : words)
    {
      struct TrieNode *pCrawl = root;
      int prefixCount = 0;
      for(char letter:word)
      {
        int index = letter - 'a';
        pCrawl = pCrawl->children[index];
        prefixCount+=pCrawl->prefixCount;
      }
      result[count++] = prefixCount;
    }
    return result;
  }
  
  vector<int> sumPrefixScores(vector<string>& words) {
    TrieNode* root = getNode();
    for(string word:words)
    {
      insert(root, word);
    }
    return solve(root, words);
  }
};