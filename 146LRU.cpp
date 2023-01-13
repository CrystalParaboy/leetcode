class LRUCache {
public:
    LRUCache(int capacity):cap(capacity) {}
    
    int get(int key) {
        if(map.find(key)==map.end()) return -1;
        else{
            int temp=map[key]->second;
            l.erase(map[key]);
            l.push_front({key, temp});
            map[key]=l.begin();
            return temp;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end())
            l.erase(map[key]);

        else if(l.size()==cap){
            int vic=l.back().first;
            map.erase(vic);
            l.pop_back();
        }
        
        l.push_front({key, value});
        map[key]=l.begin();
        
    }
private:
    int cap;
    unordered_map<int, list<pair<int ,int>>::iterator> map;
    list<pair<int ,int>> l;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
