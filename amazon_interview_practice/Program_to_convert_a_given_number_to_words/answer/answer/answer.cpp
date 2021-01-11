#include <string>
#include <iostream>

using namespace std;

inline string get_digit(char c)
{
	switch (c) {
	case '1' :		return string("one");
	case '2' :		return string("two");
	case '3' :		return string("three");
	case '4' :		return string("four");
	case '5' :		return string("five");
	case '6' :		return string("six");
	case '7' :		return string("seven");
	case '8' :		return string("eight");
	case '9' :		return string("nine");
	default :		return string("");
	}
}

inline string get_ten(char c)
{
	switch (c) {
	case '1':		return string("ten");
	case '2':		return string("twenty");
	case '3':		return string("thirty");
	case '4':		return string("fourty");
	case '5':		return string("fifty");
	case '6':		return string("sixty");
	case '7':		return string("seventy");
	case '8':		return string("eighty");
	case '9':		return string("ninty");
	default:		return string("");
	}
}

void convert_to_words(string str)
{
	string answer = string("");
	for (int i = str.length(); i > 0; --i) {
		int idx = str.length() - i;
		string num = string("");
		if (i == 2) {
			num = get_ten(str[idx]);
		} else {
			num = get_digit(str[idx]);
			if (i == 4)			num += string(" thousand");
			else if (i == 3)	num += string(" hundred");
		}
		num += string(" ");
		answer += num;
	}
	cout << answer << endl;
}

/* Driver program to test above function */
int main(void)
{
	convert_to_words("9923");
	convert_to_words("523");
	convert_to_words("89");
	convert_to_words("8989");

	return 0;
}