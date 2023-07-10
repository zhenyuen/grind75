#include <unordered_map>
#include <map>


class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        auto it = std::upper_bound(
            mp[key].begin(), 
            mp[key].end(), 
            std::pair<int, std::string>(timestamp, ""),
            [](
                const std::pair<int, std::string>& a, 
                const std::pair<int, std::string>& b) { 
                return a.first < b.first;
            }
        );
        
        return it == mp[key].begin() ? "" : std::prev(it) -> second;
    }


};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */