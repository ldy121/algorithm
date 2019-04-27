#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
	int TC, tc;
	int n, m, answer;
	priority_queue<int, vector<int>, greater<int> > park;
	queue<int> enter;
	vector<int> car;
	vector<int> car_weight;
	vector<int> price;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (tc = 1; tc <= TC; ++tc) {
		cin >> n >> m;
		if (price.size() < (n + 1))	price.reserve(n + 1);
		if (car.size() < (m + 1)) 	car.reserve(m + 1);
		if (car_weight.size() < (m + 1))car_weight.reserve(m + 1);
		for (int i = 1; i <= n; ++i) {
			int park_price;
			cin >> park_price;
			price[i] = park_price;
			park.push(i);
		}

		for (int i = 1; i <= m; ++i) {
			int weight;
			cin >> weight;
			car_weight[i] = weight;
		}

		answer = 0;
		for (int i = 0; i < (m * 2); ++i) {
			int input;
			int location;
			cin >> input;
			
			if (input < 0) {
				location = car[input * -1];
				park.push(location);
			} else {
				enter.push(input);
			}
			while (!park.empty() && !enter.empty()) {
				int car_index = enter.front();
				location = park.top();
				car[car_index] = location;
				answer += (car_weight[car_index] * price[location]);
				
				enter.pop();
				park.pop();
			}
		}
		price.clear();
		car.clear();
		car_weight.clear();
		while (!enter.empty())	enter.pop();
		while (!park.empty())	park.pop();

		cout << "#" << tc << " " << answer << endl;
	}

	return 0;
}
