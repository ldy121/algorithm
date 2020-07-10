#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool getAnswer(vector<string> &dictionary, string &S) {
	queue<int> q;
	for (q.push(0); !q.empty();) {
		for (int size = q.size();size > 0; --size) {
			int idx = q.front();
			q.pop();
			for (int i = 0; i < dictionary.size(); ++i) {
				int j = 0;
				int k = idx;
				while (j < dictionary[i].length() && k < S.length()) {
					if (dictionary[i][j] == S[k]) {
						++j;
						++k;
					} else {
						break;
					}
				}
				if (j == dictionary[i].length()) {
					if (k == S.length()) {
		    			return true;
	    			} else {
			    		q.push(k);
			    	}
				}

			}
		}
	}
	return false;
}


int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		int N;
		vector<string> dictionary;
		string S;

		cin >> N;

		for (int i = 0; i < N; ++i) {
			string str;
			cin >> str;
			dictionary.push_back(str);
		}
		cin >> S;
		cout << getAnswer(dictionary, S) << endl;	
	}
	return 0;
}


