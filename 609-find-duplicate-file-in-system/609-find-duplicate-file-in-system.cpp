class Solution {
public:
  map<string, string> getFileInfo(string s)
  {
    stringstream ss(s);
    string word;
    map<string, string> fileInfo;
    int count = 1;
    while (!ss.eof()) {
      getline(ss, word, '(');
      if(count == 1)
      {
        fileInfo["filename"] = word;
      }
      else
      {
        fileInfo["content"] = word;
      }
      count++;
    }
    return fileInfo;
  }
  
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    
    map<string, vector<string>> fileContentVsPaths;
    set<string> fileContents;
    
    for(string path: paths)
    {
      int count = 1;
      stringstream ss(path);
      string directory;
      string word;
      while (ss >> word) {
        if(count == 1)
        {
           directory = word;
        }
        else
        {
          map<string, string> fileInfo = getFileInfo(word);
          string fileContent = fileInfo["content"];
          string fileName = fileInfo["filename"];
          if(fileContentVsPaths.find(fileContent) == fileContentVsPaths.end())
          {
            fileContentVsPaths[fileContent]  = vector<string>();
          }
          fileContentVsPaths[fileContent].push_back(directory + "/" + fileName);
          fileContents.insert(fileContent);
        }
        count++;
      }
    }
    vector<vector<string>> result;
    for(string fileContent : fileContents)
    {
      if(fileContentVsPaths[fileContent].size()>1)
        result.push_back(fileContentVsPaths[fileContent]);
    }
    return result;
  }
};