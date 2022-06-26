// Compares two course values
bool compareDay(vector<int>& a, vector<int>& b)
{
  if(a[1] == b[1])
    return (a[0] < b[0]);
  return (a[1] < b[1]);
}

class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), compareDay);
    priority_queue<int> coursesTaken;
    int day = 0;
    for(vector<int> course : courses)
    {
      coursesTaken.push(course[0]);
      day += course[0];
      if(day > course[1])
      {
        int discardDuration = coursesTaken.top();
        coursesTaken.pop();
        day -= discardDuration;
      }
    }
    return coursesTaken.size();
  }
};