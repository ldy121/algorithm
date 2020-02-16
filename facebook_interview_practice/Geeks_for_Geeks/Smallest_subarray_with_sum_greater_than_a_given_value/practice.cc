#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> get_answer(int arr[], int N, int x)
{
	queue<int> q;
	vector<int> answer;
	int sum = 0, min_sum = 99999999, from = 0, to = -1;

	for (int i = 0; i < N; ++i) {
		q.push(i);
		sum += arr[i];
		while (x < sum) {
			if (sum < min_sum) {
				from = q.front();
				to = i;
				min_sum = sum;
			}
			sum -= arr[q.front()];
			q.pop();
		}
	}

	for (int i = from; i <= to; ++i) {
		answer.push_back(arr[i]);
	}

	return answer;
}

int main(void)
{
	int arr1[] = {1, 4, 45, 6, 0, 19};
	int x1 = 51;
	int arr2[] = {1, 10, 5, 2, 7};
	int x2 = 9;
	int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
	int x3 = 280;
	int arr4[] = {1, 2, 4};
	int x4;

	vector<int> ans1 = get_answer(arr1, sizeof(arr1) / sizeof(int), x1);
	for (int i = 0; i < ans1.size(); ++i) {
		cout << ans1[i] << " ";
	}
	cout << endl;

	vector<int> ans2 = get_answer(arr2, sizeof(arr2) / sizeof(int), x2);
	for (int i = 0; i < ans2.size(); ++i) {
		cout << ans2[i] << " ";
	}
	cout << endl;

	vector<int> ans3 = get_answer(arr3, sizeof(arr3) / sizeof(int), x3);
	for (int i = 0; i < ans3.size(); ++i) {
		cout << ans3[i] << " ";
	}
	cout << endl;

	vector<int> ans4 = get_answer(arr4, sizeof(arr4) / sizeof(int), x4);
	for (int i = 0; i < ans4.size(); ++i) {
		cout << ans4[i] << " ";
	}
	cout << endl;
}
