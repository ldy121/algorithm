#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> stringSplit(string& str, char ch) {
	vector<string> ret;
  int start, len, i;

	for (i = 0, start = 0, len = 0; i < str.length(); ++i) {
		if (str[i] == ch) {
			ret.push_back(str.substr(start, len));
			start = i + 1;
			len = 0;
		} else {
			++len;
		}
	}
  ret.push_back(str.substr(start, len));

	return ret;
}

int getAnswer(unordered_map<string, int> &table, string number) {
	vector<string> split = stringSplit(number, ' ');
	int ret = 0;

	for (int i = 0; i < split.size(); ++i) {
    int val = table[split[i]];
    if (val == 1000 || val == 100) {
      ret *= val;
    } else {
      ret += val;
    }	
	}

	return ret;
}


int main(void) {
	unordered_map<string, int> table;
	table["Thousand"] = 1000;
  table["Hundred"] = 100;
  table["Ninty"] = 90;
  table["Eighty"] = 80;
  table["Seventy"] = 70;
  table["Sixty"] = 60;
  table["Fifty"] = 50;
  table["Forty"] = 40;
  table["Thirty"] = 30;
  table["Twenty"] = 20;
  table["Ten"] = 10;
  table["Nine"] = 9;
  table["Eight"] = 8;
  table["Seven"] = 7;
  table["Six"] = 6;
  table["Five"] = 5;
  table["Four"] = 4;
  table["Three"] = 3;
  table["Two"] = 2;
  table["One"] = 1;

  cout << getAnswer(table, string("One Thousand")) << endl;
  cout << getAnswer(table, string("Two Hundred Thirty Four")) << endl;
}

