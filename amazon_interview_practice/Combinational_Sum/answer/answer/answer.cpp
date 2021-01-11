// Driver code 
#include <iostream>
#include <vector>

using namespace std;

void get_answer(vector<vector<int> >& answer, vector<int>& ans, vector<int>&ar, int index, int sum)
{
	if (sum == 0) {
		answer.push_back(ans);
	} else if (ar[index] <= sum) {
		for (int i = index; (i < ar.size()) && (ar[i] <= sum); ++i) {
			ans.push_back(ar[i]);
			get_answer(answer, ans, ar, i, sum - ar[i]);
			ans.pop_back();
		}
	}
}

vector<vector<int> > combinationSum(vector<int>&ar, int sum)
{
	vector<vector<int> > ret;
	vector<int> answer;

	for (int i = 0; i < ar.size(); ++i) {
		if (ar[i] <= sum) {
			answer.push_back(ar[i]);
			get_answer(ret, answer, ar, i, sum - ar[i]);
			answer.pop_back();
		}
	}

	return ret;
}

int main()
{
	vector<int> ar;
	ar.push_back(2);
	ar.push_back(4);
	ar.push_back(6);
	ar.push_back(8);
	int n = ar.size();

	int sum = 8; // set value of sum 
	vector<vector<int> > res = combinationSum(ar, sum);

	// If result is empty, then 
	if (res.size() == 0)
	{
		cout << "Emptyn";
		return 0;
	}

	// Print all combinations stored in res. 
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i].size() > 0)
		{
			cout << " ( ";
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << ")";
		}
	}
}