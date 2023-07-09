#include <algorithm>
#include <unordered_map>
#include <utility>
#include <list>

class LRUCache {
public:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mp;
    std::list<std::pair<int, int>> l;
    int c;
    
    LRUCache(int capacity) : c(capacity) {

    }
    
    int get(int key) {
        auto e = mp.find(key);
        if (e != mp.end()) {
            auto it = mp.at(key);
            l.splice(l.end(), l, it);
            
            mp.at(key) = std::prev(l.end());

            return l.back().second;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            auto it = mp.at(key);
            l.erase(it);
            l.push_back({key, value});
            mp.at(key) = std::prev(l.end());
        } else {
            if (l.size() == c) {
                auto key_to_delete = l.front().first;
                l.pop_front();
                mp.erase(key_to_delete);
            }
            l.push_back({key, value});
            mp.insert({key, std::prev(l.end())});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */