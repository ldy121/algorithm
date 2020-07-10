// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function that returns the sub-array 
vector<int> findSubarray(int a[], int k, int n) 
{ 
  
    // Data-structure to store all 
    // the sub-arrays of size K 
    vector<vector<int> > vec; 
  
    // Iterate to find all the sub-arrays 
    for (int i = 0; i < n - k + 1; i++) { 
        vector<int> temp; 
  
        // Store the sub-array elements in the array 
        for (int j = i; j < i + k; j++) { 
            temp.push_back(a[j]); 
        } 
  
        // Push the vector in the container 
        vec.push_back(temp); 
    } 
  
    // Sort the vector of elements 
    sort(vec.begin(), vec.end()); 
  
    // The last sub-array in the sorted order 
    // will be the answer 
    return vec[vec.size() - 1]; 
} 
  
// Driver code 
int main() 
{ 
//    int a[] = { 1, 4, 3, 2, 5 }; 
    int a[] = {1, 9, 2, 7, 9, 3};
//    int k = 4; 
    int k = 3;
    int n = sizeof(a) / sizeof(a[0]); 
  
    // Get the sub-array 
    vector<int> ans = findSubarray(a, k, n); 
  
    for (auto it : ans) 
        cout << it << " "; 
} 
