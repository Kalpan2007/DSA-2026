class MedianFinder {
public:
    multiset<int> ms;
    multiset<int>::iterator mid;

    MedianFinder() {}

    void addNum(int num) {
        int n = ms.size();
        ms.insert(num);

        if (n == 0) {
            mid = ms.begin();
            return;
        }

        if (num < *mid) {
            if (n % 2 == 1) mid--;
        } else {
            if (n % 2 == 0) mid++;
        }
    }

    double findMedian() {
        int n = ms.size();
        if (n % 2 == 1) return *mid;
        return (*mid + *next(mid)) / 2.0;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */