class EventManager {
public:
    priority_queue<pair<int,int> , vector<pair<int ,int>> , greater<>> pq;
    unordered_map<int , int> cp;
    unordered_set<int> active;
    
    EventManager(vector<vector<int>>& events) {
        for(auto& e : events){
            int eventId = e[0] , priority = e[1];
            cp[eventId] = priority;
            active.insert(eventId);
            pq.push({-priority,eventId });
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        cp[eventId] = newPriority;
        pq.push({-newPriority , eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
        auto [n , eventId] = pq.top();
            pq.pop();

        if(!active.count(eventId)) continue;
        if(-n != cp[eventId]) continue;

        active.erase(eventId);
        cp.erase(eventId);
        return eventId;
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */