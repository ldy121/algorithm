#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class LRUCache
{
private:
	unordered_map<int, int> m_dataTag;
	unordered_map<int, list<int>::iterator> m_lruTag;
	vector<int> m_data;
	list<int> m_lru;
	int m_size;
	const int invalid = -1;

public:
    LRUCache(int cap)
    {
			m_size = cap;
    }
    int get(int key)
    {
			if (m_dataTag.find(key) == m_dataTag.end() || m_dataTag[key] == invalid) {
				return invalid;
			}
			m_lru.erase(m_lruTag[key]);
			m_lru.push_front(key);
			m_lruTag[key] = m_lru.begin();
			return m_data[m_dataTag[key]];
    }
    void set(int key, int value)
    {
			if (m_dataTag.find(key) == m_dataTag.end()) {
				m_dataTag[key] = invalid;
				m_lruTag[key] = m_lru.end();
			}

			if (m_dataTag[key] == invalid) {
				if (m_data.size() < m_size) {
					m_dataTag[key] = m_data.size();
					m_data.push_back(invalid);
				} else {
					list<int>::reverse_iterator iter = m_lru.rbegin();
					m_dataTag[key] = m_dataTag[*iter];
					m_dataTag[*iter] = invalid;
					m_lru.pop_back();
				}
			} else {
				m_lru.erase(m_lruTag[key]);
			}
			m_lru.push_front(key);
			m_lruTag[key] = m_lru.begin();
			m_data[m_dataTag[key]] = value;
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
//	testCase1();
	testCase2();
}

