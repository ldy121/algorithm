// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int maxCoins(int A[],int );


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		cout<<maxCoins(a,n)<<endl;
		
	}
	return 0;
}// } Driver Code Ends


const int invalid = -1;

int getAnswer(int A[], vector<vector <int> > &answer, int left, int right) {
	if (left > right) {
		return 0;
	} else if (left == right) {	
		return A[left];
	} else if (answer[left][right] != invalid) {
		return answer[left][right];
	}

	int leftleft = getAnswer(A, answer, left + 2, right);
    int leftright = getAnswer(A, answer, left + 1, right - 1);
    int rightright = getAnswer(A, answer, left, right - 2);
    int leftSelect = A[left] + ((leftleft < leftright) ? (leftleft) : (leftright));
    int rightSelect = A[right] + ((rightright < leftright) ? (rightright) : (leftright));

	answer[left][right] = (leftSelect < rightSelect) ? rightSelect : leftSelect;
	return answer[left][right];
}


/*You are required to complete below method */
int maxCoins(int A[],int N)
{
	vector<vector<int> > answer;
	for (int i = 0; i < N; ++i) {
		answer.push_back(vector<int>(N, invalid));
	}
	return getAnswer(A, answer, 0, N - 1);
}
