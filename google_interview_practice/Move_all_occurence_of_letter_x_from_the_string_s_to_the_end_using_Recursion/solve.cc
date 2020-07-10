#include <string>
#include <iostream>

using namespace std;

void getAnswer(string &dst, string &src, int idx) {
	if (dst.length() == src.length()) {
		return;
	}

	if (idx < src.length()) {
		if (src[idx] != 'x') {
			dst += src[idx];
		}
	} else {
		dst += 'x';
	}
	getAnswer(dst, src, idx + 1);
}

string moveAtEnd(string &str) {
	string ret;
	getAnswer(ret, str, 0);
	return ret;
}
 

 
// Driver code 
int main() 
{ 
    string s = "geekxsforgexxeksxx"; 
  
    cout << moveAtEnd(s) << endl;
  
    return 0; 
} 
