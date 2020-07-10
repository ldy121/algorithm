#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class person {
public :
  person(int birth, int death) : m_birth(birth), m_death(death) {};
	int m_birth;
	int m_death;
};

bool comp(person a, person b) {
	return (a.m_birth < b.m_death) ||
((a.m_birth == b.m_birth) && (a.m_death < b.m_death));
}

int getAnswer(vector<person> &people) {
	priority_queue<int, vector<int>, greater<int> > q;
	sort(people.begin(), people.end(), comp);
	int answer = 0;

	for (int i = 0; i < people.size(); ++i) {
		while (!q.empty() && q.top() < people[i].m_birth) {
			q.pop();
		}
		q.push(people[i].m_death);
		if (answer < q.size()) {
			answer = q.size();
		}
	}
	return answer;
}

int main(void) {
	vector<person> people;
	people.push_back(person(1900, 1903));
	people.push_back(person(1903, 1905));
	people.push_back(person(1900, 1902));
	people.push_back(person(1905, 1906));
	people.push_back(person(1902, 1903));
	people.push_back(person(1904, 1908));
	people.push_back(person(1905, 1907));
	cout << getAnswer(people) << endl;
}

