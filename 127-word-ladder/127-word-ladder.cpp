unordered_map<string,bool> wordOccurrence;
class Graph {
  int numVertices;
  map<string,int> vertexDistance;

   public:
  Graph(int vertices);
  void setVertices(vector<string> &vertices);
  void addVertex(string &vertex);
  int BFS(string &startVertex, string &endVertex, vector<string>& wordList);
};

Graph::Graph(int vertices) {
  numVertices = vertices;
}

void Graph::setVertices(vector<string> &vertices)
{ 
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
        string temp = currVertex;
        temp[i] = 'a' + j;
        if(temp!=currVertex && wordOccurrence[temp])
        {
          string adjVertex = temp;
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
    Graph g(wordList.size()+1);
    g.setVertices(wordList);
    g.addVertex(beginWord);
    return g.BFS(beginWord, endWord, wordList);
  }
};