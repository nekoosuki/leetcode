#include <list>
#include <vector>
using namespace std;
//链地址
class MyHashMap {
   private:
    vector<list<pair<int, int>>> data;
    static const long hash = 5381;
    int hash_int(int key) { return key % hash; }

   public:
    MyHashMap() : data(hash) {}

    void put(int key, int value) {
        int hash = hash_int(key);
        for (auto i = data[hash].begin(); i != data[hash].end(); i++) {
            if (i->first == key) {
                i->second = value;
                return;
            }
        }
        data[hash].push_back(make_pair(key, value));
    }

    int get(int key) {
        int hash = hash_int(key);
        for (auto i = data[hash].begin(); i != data[hash].end(); i++) {
            if (i->first == key) return i->second;
        }
        return -1;
    }

    void remove(int key) {
        int hash = hash_int(key);
        for (auto i = data[hash].begin(); i != data[hash].end(); i++) {
            if (i->first == key) {
                data[hash].erase(i);
                return;
            }
        }
    }
};