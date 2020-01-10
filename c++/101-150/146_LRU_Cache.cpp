#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <stack>


using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 哈希表+双向链表



class LRUCache {
public:
	LRUCache(int capacity) {
		this->cap = capacity;
	}

	int get(int key) {
		auto it = map.find(key);
		if (it == map.end()) return -1;

		//key 存在，把(key,value)换到队头
		pair<int, int> kv = *map[key];
		cache.erase(map[key]);
		cache.push_front(kv);

		// 更新(key,value)在cache中的位置
		map[key] = cache.begin();
		return kv.second;  // value
	}

	void put(int key, int value) {
		// 先判断key是否已经存在
		auto it = map.find(key);
		if (it == map.end()) {
			// key不存在，判断cache是否已满
			if (cache.size() == cap) {
				// cache已满，删除尾部的键值对
				auto lastPair = cache.back();
				int lastKey = lastPair.first;
				map.erase(lastKey);
				cache.pop_back();
			}
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();

		}
		else {
			// key存在，更改value并换到对头
			cache.erase(map[key]);
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();
		}
	}
private:
	int cap;
	// 双链表：存(key,value)
	list<pair<int, int>> cache;
	// key映射到(key,value)在cache中的位置
	unordered_map<int, list<pair<int, int>>::iterator> map;
};



int main()
{
	


	cin.get();
}
