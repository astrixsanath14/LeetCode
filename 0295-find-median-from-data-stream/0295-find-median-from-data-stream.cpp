class MedianFinder {
public:
    priority_queue<int> smaller, larger;
    int totalCount = 0;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smaller.push(num);
        larger.push(-smaller.top());
        smaller.pop();
        totalCount++;
        if(larger.size() > (1+smaller.size()))
        {
            smaller.push(-larger.top());
            larger.pop();
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