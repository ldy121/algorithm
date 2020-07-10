// Driver code 
#include <string>
#include <iostream>

using namespace std;

int Min_repetation(string &A, string &B) {
	string a;

	while (a.length() < B.length() * 2) {
		a += A;
	}

  size_t idx = a.find(B);
	if (idx == string::npos) {
		return -1;
	}

	int ret = (idx + B.length()) / A.length();
	if ((idx + B.length()) % A.length() > 0) {
		++ret;
	}
	return ret;
}

int main() 
{ 
//    string A = "abcd", B = "cdabcdab"; 
//    string A = "ba", B = "ab"; 
//    string A = "ab", B = "b";
    string A = "ab", B = "bc";
      
    // Function call 
    cout << Min_repetation(A, B) << endl; 
      
    return 0; 
} 
