unordered_map<string,bool> wordOccurrence;
class Graph {
  map<string,int> vertexDistance;
  public:
  Graph(vector<string> &);
  void addVertex(string &vertex);
  int BFS(string &startVertex, string &endVertex, vector<string>& wordList);
};

Graph::Graph(vector<string> &vertices) {
  for (string vertex:vertices)
    addVertex(vertex);
}

void Graph::addVertex(string &vertex)
{
  vertexDistance[vertex] = -1;
}

// BFS algorithm 
int Graph::BFS(string &startVertex, string &endVertex, vector<string>& wordList) {
  list<string> queue;
  queue.push_back(startVertex);
  vertexDistance[startVertex] = 1;
  int len = wordList[0].length();
  while (!queue.empty()) 
  {
    string currVertex = queue.front();
    queue.pop_front();
    
    //Modified
    for(int i=0;i<len;i++)
    {
      for(int j=0;j<26;j++)
      {
        string adjVertex = currVertex;
        adjVertex[i] = 'a' + j;
        if(adjVertex!=currVertex && wordOccurrence[adjVertex])
        {
          if (vertexDistance[adjVertex]==-1) {
            vertexDistance[adjVertex] = vertexDistance[currVertex]+1;
            queue.push_back(adjVertex);
            if(adjVertex == endVertex)
            {
              return vertexDistance[adjVertex];
            }
          }
        }
      }
    }
  }
  return 0;
}

class Solution {
public:
  
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordOccurrence.clear();
    for(auto word:wordList)
      wordOccurrence[word] = true;
    if(!wordOccurrence[endWord])
      return 0;
    Graph g(wordList);
    g.addVertex(beginWord);
    return g.BFS(beginWord, endWord, wordList);
  }
};