#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numr, int denr)
{
	unordered_map<int, bool> hash;
	string ret;

	for (int operand = (numr - ((numr / denr) * denr)) * 10; (operand > 0) && (hash.size() < numr);
		operand = (operand - ((operand / denr) * denr)) * 10) {
		int val = operand % denr;

		if (hash.find(val) == hash.end()) {
			int input = operand / denr;
			ret += (input + '0');
			hash[val] = true;
		} else {
			return ret;
		}
	}

	return string("");
}

// Driver code 
int main()
{
	int num_arr[]  = {8, 50, 11};
	int denr_arr[] = {3, 22, 2};
	
	for (int i = 0; i < 3; ++i) {
		string res = fractionToDecimal(num_arr[i], denr_arr[i]);
		if (res == "")
			cout << "No recurring sequence" << endl;
		else
			cout << "Recurring sequence is " << res << endl;
	}
	return 0;
}