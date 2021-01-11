#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache {
public :
	LRUCache(int size) {
		m_iMax = size;
	}

	~LRUCache() {

	}

	void refer(int addr) {
		int idx = 0;

		if (m_tag.find(addr) == m_tag.end()) {	// cache miss
			if (m_cache.size() == m_iMax) {		// cache evict
				for (idx = -1; idx < 0;) {
					int i = m_request.front();
					int j = m_tag[i];

					m_request.pop();

					if (--m_last[j] == 0) {
						idx = j;

						m_tag.erase(i);
						m_cache[j] = addr;
						m_last[j] = 1;
					}
				}
			} else {							// push cache
				idx = m_cache.size();
				m_cache.push_back(addr);
				m_last.push_back(1);
			}
			m_tag[addr] = idx;
		} else {
			idx = m_tag[addr];
			++m_last[idx];
		}

		m_request.push(addr);
	}

	void display(void) {
		for (int i = 0; i < m_cache.size(); ++i) {
			cout << m_cache[i] << endl;
		}
	}

private :
	int m_iMax;
	queue<int> m_request;
	unordered_map<int, int> m_tag;
	vector<int> m_cache;
	vector<int> m_last;
};

// Driver Code 
int main()
{

	LRUCache ca(4);
/*
	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);
*/
//	1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5

	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(4);
	ca.refer(1);
	ca.refer(2);
	ca.refer(5);
	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(4);
	ca.refer(5);

	ca.display();

	return 0;
}