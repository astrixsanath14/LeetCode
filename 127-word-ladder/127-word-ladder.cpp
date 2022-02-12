unordered_map<string,bool> wordOccurrence;
class Graph {
  int numVertices;
  map<string, list<string>> adjLists;
  map<string,bool> visited;
  map<string,int> vertexDistance;

   public:
  Graph(int vertices);
  void setVertices(vector<string> &vertices);
  void addVertex(string &vertex);
  void addEdge(string &src, string &dest);
  int BFS(string &startVertex, string &endVertex, vector<string>& wordList);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
  numVertices = vertices;
}

// Add edges to the graph
void Graph::addEdge(string &src, string &dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}

void Graph::setVertices(vector<string> &vertices)
{ 
  for (string vertex:vertices)
  {
    addVertex(vertex);
  }
}

void Graph::addVertex(string &vertex)
{
    adjLists[vertex] = list<string>();
    visited[vertex] = false;
    vertexDistance[vertex] = -1;
}

// BFS algorithm
int Graph::BFS(string &startVertex, string &endVertex, vector<string>& wordList) {
  list<string> queue;
  queue.push_back(startVertex);
  
  visited[startVertex] = true;
  
  list<string>::iterator i;
  vertexDistance[startVertex] = 1;
  int len = wordList[0].length();
  while (!queue.empty()) {
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
          if (!visited[adjVertex]) {
            vertexDistance[adjVertex] = vertexDistance[currVertex]+1;
            visited[adjVertex] = true;
            queue.push_back(adjVertex);
            if(adjVertex == endVertex)
            {
              return vertexDistance[adjVertex];
            }
          }
        }
      }
    }
    
    // for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
    //   string adjVertex = *i;
    //   if (!visited[adjVertex]) {
    //     vertexDistance[adjVertex] = vertexDistance[currVertex]+1;
    //     visited[adjVertex] = true;
    //     queue.push_back(adjVertex);
    //     if(adjVertex == endVertex)
    //     {
    //       return vertexDistance[adjVertex];
    //     }
    //   }
    // }
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
    int len = wordList[0].length();
    Graph g(wordList.size()+1);
    g.setVertices(wordList);
    g.addVertex(beginWord);
    // if(!wordOccurrence[beginWord])
    // {
    //   bool foundAtLeastOneSeq = false;
    //   for(int i=0;i<len;i++)
    //   {
    //     for(int j=0;j<=26;j++)
    //     {
    //       string temp = beginWord;
    //       temp[i] = 'a'+j;
    //       if(temp != beginWord && wordOccurrence[temp])
    //       {
    //         foundAtLeastOneSeq = true;
    //         g.addEdge(beginWord, temp);
    //       }
    //     }
    //   }
    //   if(!foundAtLeastOneSeq)
    //     return 0;
    // }
    return g.BFS(beginWord, endWord, wordList);
  }
};