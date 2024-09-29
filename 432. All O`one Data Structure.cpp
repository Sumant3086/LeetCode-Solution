// 432. All O`one Data Structure
// Solved
// Hard
// Topics
// Companies
// Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

// Implement the AllOne class:

// AllOne() Initializes the object of the data structure.
// inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
// dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
// getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
// getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
// Note that each function must run in O(1) average time complexity.

 

// Example 1:

// Input
// ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
// [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
// Output
// [null, null, null, "hello", "hello", null, "hello", "leet"]

// Explanation
// AllOne allOne = new AllOne();
// allOne.inc("hello");
// allOne.inc("hello");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "hello"
// allOne.inc("leet");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "leet"
 

// Constraints:

// 1 <= key.length <= 10
// key consists of lowercase English letters.
// It is guaranteed that for each call to dec, key is existing in the data structure.
// At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.

class AllOne {
public:
unordered_map<string, int> m;
    AllOne() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    }
    void updateMin() {        
        _min.second = INT_MAX;
        for(auto & nd : m) {
            if(_min.second > nd.second) {
                _min.second = nd.second;
                _min.first = nd.first;
            }
        }
    }
    void updateMax() {        
        _max.second = INT_MIN;
        for(auto & nd : m) {
            if(_max.second < nd.second) {
                _max.second = nd.second;
                _max.first = nd.first;
            }
        }
    }
    void inc(string key) {
        auto & v = m[key];
        ++v;
        if(v > _max.second) {
            _max.second = v;
            _max.first = key;
        }
        if(key == _min.first) {
            updateMin();
        }
        if(_min.second > v || _min.first.empty()) {
            _min.first = key;
            _min.second = v;
        }
    }
    void dec(string key) {
        m[key]--;
        if(m[key] ==0)
            m.erase(key);
        _min.first = _max.first = "";
    }
    string getMaxKey() {
        if(!_max.first.empty())
            return _max.first;
        updateMax();
        return _max.first;
    }
    string getMinKey() {
        if(!_min.first.empty())
            return _min.first;

        updateMin();
        return _min.first;
    }
    pair<string, int> _min{{}, 0};
    pair<string, int> _max{{}, 0};
};