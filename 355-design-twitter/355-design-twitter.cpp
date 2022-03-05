#define USER_COUNT 500

struct TweetInfo
{
  int userID;
  int tweetID;
  int time;
  TweetInfo(int _userID,int _tweetID,int _time)
  {
    userID = _userID;
    tweetID = _tweetID;
    time = _time;
  }
};


// this is an structure which implements the
// operator overloading
struct CompareTime {
    bool operator()(TweetInfo const& tweet1, TweetInfo const& tweet2)
    {
        // return "true" if "tweet1" is ordered
        // before "tweet2", for example:
        return tweet1.time < tweet2.time;
    }
};

void print_queue(priority_queue<TweetInfo, vector<TweetInfo>, CompareTime> q) { 
  // NB: pass by value so the print uses a copy
  cout<<"Printing..."<<"\n";
  while(!q.empty()) {
    cout << "TweetID: "<<q.top().tweetID << " Time: " << q.top().time << " UserID: " << q.top().userID << "\n";
    q.pop();
  }
  cout << '\n';
}

class Twitter {
  map<int,deque<TweetInfo>> userIDVsTweetInfoMap;//UserID -> {time,tweetID};
  int followerGrid[USER_COUNT][USER_COUNT];
  int time;
public:
  Twitter() {
    memset(followerGrid, 0, sizeof(followerGrid));
    for(int userID=0;userID<USER_COUNT;userID++)
    {
      followerGrid[userID][userID] = 1;
      userIDVsTweetInfoMap[userID] = deque<TweetInfo>();
    }
    time = 0;
  }

  void postTweet(int userID, int tweetID) {
    userIDVsTweetInfoMap[userID].push_back(TweetInfo(userID, tweetID, time++));
  }

  vector<int> getNewsFeed(int userID) {
    
    priority_queue<TweetInfo, vector<TweetInfo>, CompareTime> recentTweets;
    
    map<int,deque<TweetInfo>> userIDVsTweetInfoMapTemp = userIDVsTweetInfoMap;
    for(int followeeID = 0; followeeID<USER_COUNT;followeeID++)
    {
      if(!followerGrid[userID][followeeID])
      {
        continue;
      }
      if(!userIDVsTweetInfoMapTemp[followeeID].empty()){
        recentTweets.push(userIDVsTweetInfoMapTemp[followeeID].back());
        userIDVsTweetInfoMapTemp[followeeID].pop_back();
      }
    }
    vector<int> recentTweets_10;
    for(int tweetNo = 1;tweetNo<=10 && !recentTweets.empty();tweetNo++)
    {
      // print_queue(recentTweets);
      TweetInfo recentTweet = recentTweets.top();
      recentTweets.pop();
      int tweetUserID = recentTweet.userID;
      if(!userIDVsTweetInfoMapTemp[tweetUserID].empty()){
        recentTweets.push(userIDVsTweetInfoMapTemp[tweetUserID].back());
        userIDVsTweetInfoMapTemp[tweetUserID].pop_back();
      }
      recentTweets_10.push_back(recentTweet.tweetID);
    }
    return recentTweets_10;
  }

  void follow(int followerId, int followeeID) {
    followerGrid[followerId][followeeID] = 1;
  }

  void unfollow(int followerId, int followeeId) {
    followerGrid[followerId][followeeId] = 0;
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

/*

["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]
["Twitter","postTweet","postTweet","getNewsFeed"]
[[],[1,5],[1,3],[1]]

*/