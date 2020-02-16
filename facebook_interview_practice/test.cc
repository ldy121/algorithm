#include <iostream>

using namespace std;


int main(void)
{
	char * test = "\\\\";

	for (int i = 0; test[i] != '\0'; ++i) {
		cout << i << endl;
	}
}
