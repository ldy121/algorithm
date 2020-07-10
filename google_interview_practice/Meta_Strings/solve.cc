#include <iostream>
using namespace std;

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
	    string A, B;
	    int idx = -1;
	    int i;
	    cin >> A;
	    cin >> B;
	    for (i = 0; (i < A.length()) && (i < B.length()); ++i) {
	        if (A[i] == B[i]) {
	            continue;
	        }
	        if (idx == -1) {
	            idx = i;
	            continue;
	        } else if (idx == -2) {
	            break;
	        }
            if (A[idx] == B[i] && A[i] == B[idx]) {
                idx = -2;
            } else {
                break;
            }
	    }
	    
	    cout << (i == A.length() && i == B.length() && idx == -2) << endl;
	}
	return 0;
}
