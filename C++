class MedianFinder {
private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxheap.empty() || num <= maxheap.top())        //this will be a starter and if the numbers are less than the first(top) number of the maxheap
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }

        
        //the very first number will pass through the if an else if loop; Ex: maxheap.size() = 1; minheapsize = 0; then 1 > 0 + 1 =  1 > 1 which will not go into the loop
        if(maxheap.size() > minheap.size() + 1)            //minheap of 1 of difference to make it balance
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size())           //the very first number will never go into this loop also because 0 > 1 does not make sense
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        
        if(maxheap.size() > minheap.size())             //this will be number; Ex: maxheap: 5,3;  minheap: 6;  3, 5, 6; which means 5 will always be the median in this case 
        {
            return maxheap.top();                       //the very first(top) value will be the median
        }
        else
        {
            return (maxheap.top() + minheap.top()) / 2.0;           //if the case is even; Ex: maxheap: 5,3  minheap: 6, 10; 3,5,6,10; which means the middle to has to add together and divide by 2 to find out the median
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
