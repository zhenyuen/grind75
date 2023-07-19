#include <queue>
#include <vector>

class MedianFinder {
public:
    std::priority_queue<int> pq_min;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq_max;
    
    void addNum(int num) {
        pq_max.push(num);
        pq_min.push(pq_max.top());
        pq_max.pop();

        if (pq_max.size() < pq_min.size()) {
            pq_max.push(pq_min.top());
            pq_min.pop();
        }
    }
    
    double findMedian() {
        if (pq_max.size() > pq_min.size()) {
            return pq_max.top();
        }
        return (pq_max.top() + pq_min.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */