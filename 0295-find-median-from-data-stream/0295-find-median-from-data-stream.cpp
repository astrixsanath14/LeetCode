class MedianFinder {
public:
    priority_queue<int> smaller, larger;
    int totalCount = 0;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smaller.push(num);
        totalCount++;
        if(smaller.size() > larger.size())
        {
            larger.push(-smaller.top());
            smaller.pop();
        }
        else if(smaller.top() > -larger.top())
        {
            int smallerTop = smaller.top();
            int largerTop = -larger.top();
            smaller.pop();
            larger.pop();
            smaller.push(largerTop);
            larger.push(-smallerTop);
        }
    }
    
    double findMedian() {
        double median = -larger.top();
        if(totalCount%2==0)
        {
            median = (median + smaller.top())/2;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */