#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

const int invalid = -1;
class LRUCache {
private :
	unordered_map<int, list<int>::iterator> m_lru;
	unordered_map<int, int> m_cache;
	int m_maxSize;
	list<int> m_key;
	vector<int> m_memory;

public :
	LRUCache(int maxSize) : m_maxSize(maxSize) {};
	int get(int key) {
		if (m_lru.find(key) != m_lru.end() && m_lru[key] != m_key.end()) {
			m_key.erase(m_lru[key]);
			m_key.push_front(key);
			m_lru[key] = m_key.begin();

			return m_memory[m_cache[key]];
		} else {
			return invalid;
		}
	}
	void set(int key, int val) {
		if (m_lru.find(key) == m_lru.end()) {
			m_lru[key] = m_key.end();
		}
		if (m_lru[key] == m_key.end()) {
			if (m_memory.size() < m_maxSize) {
				m_cache[key] = m_memory.size();
				m_memory.push_back(invalid);
			} else {
				int evict = *m_key.rbegin();
				m_key.pop_back();

				m_cache[key] = m_cache[evict];

				m_lru[evict] = m_key.end();
				m_cache[evict] = invalid;
			}
	  } else {
			m_key.erase(m_lru[key]);
		}
		m_key.push_front(key);
		m_lru[key] = m_key.begin();
		m_memory[m_cache[key]] = val;
	}
};


void testCase1(void) {
	LRUCache lru (2);
	lru.set(1, 2);
	cout << lru.get(1) << endl;
	lru.set(1, 2);
	cout << lru.get(1) << endl;
}

void testCase2(void) {
	LRUCache lru (2);
	lru.set(1, 2);
	lru.set(2, 3);
	lru.set(1, 5);
	lru.set(4, 5);
	lru.set(6, 7);
	cout << lru.get(4) << endl;
	cout << lru.get(1) << endl;
}

int main(void) {
	testCase1();
	testCase2();
}

