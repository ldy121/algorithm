#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class interval {
public :
	int m_x;
	int m_y;
	interval(int x, int y) : m_x(x), m_y(y) {};
};

const int invalid = -1;

bool comp(interval a, interval b) {
	return (a.m_x < b.m_x) || ((a.m_x == b.m_x) && (a.m_y < b.m_y));
}

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		int N;
		vector<interval> intervals;
		vector<interval> answer;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int x, y;
			cin >> x >> y;
		  intervals.push_back(interval(x, y));
    }
    sort(intervals.begin(), intervals.end(), comp);

		for (int i = 0; i < intervals.size(); ++i) {
			cout << intervals[i].m_x << ',' << intervals[i].m_y << endl;
	  }

    for (int i = 0; i < intervals.size(); ++i) {
      if (intervals[i].m_x == invalid) {
        continue;
      }

      int x = intervals[i].m_x;
      int y = intervals[i].m_y;

      for (int j = i + 1; j < intervals.size(); ++j) {
        if (intervals[j].m_x <= y) {
         intervals[j].m_x = invalid;
         if (y < intervals[j].m_y) {
 	        y = intervals[j].m_y;
                }
        } else {
         break;
        }
      }

      answer.push_back(interval(x, y));
    }

    for (int i = 0; i < answer.size(); ++i) {
      cout << answer[i].m_x << ' ' << answer[i].m_y << ' ';
    }
    cout << endl;
	}
	return 0;
}


