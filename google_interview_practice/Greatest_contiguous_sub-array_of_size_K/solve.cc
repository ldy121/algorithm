// Driver code 
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


vector<int> findSubarray(vector<int> &arr, int k) {
	vector<int> ret;
	queue<int> q;
	int max = 0, idx = -1, sum = 0;
	
	for (int i = 0; i < arr.size(); ++i) {
		q.push(i);
		sum += arr[i];

		while (q.size() > k) {
			int j= q.front();
			sum -= arr[j];
			q.pop();
		}

		if (q.size() < k) {
			continue;
		}

		if (max < sum) {
			max = sum;
			idx = q.front();
		}
	}

	for (int i = idx, j = 0; j < k; ++j, ++i) {
		ret.push_back(arr[i]);
	}

	return ret;
}


int main() {
    vector<int> a { 1, 4, 3, 2, 5 }; 
    vector<int> a2 {1, 9, 2, 7, 9, 3};
    int k = 4; 
    int K = 3;
	
    // Get the sub-array 
    vector<int> ans = findSubarray(a, k); 
    vector<int> ans2 = findSubarray(a2, K); 
  
    for (auto it : ans) 
        cout << it << " "; 
    cout << endl;
    for (auto it : ans2) 
        cout << it << " "; 
    cout << endl;
} 
