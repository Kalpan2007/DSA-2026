class SmallestInfiniteSet {
public:
    set<int> s;
    int current;
    SmallestInfiniteSet() { current = 1; }

    int popSmallest() {
        if (!s.empty()) {
            int pop_val = *s.begin();
            s.erase(s.begin());
            return pop_val;
        }
        return current++;
    }

    void addBack(int num) {
        if (num < current) {
            s.insert(num);
        }
    }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */