#include <iostream> 
using namespace std; 
long long countInversions(const int arr[], int n) { 
long long inv = 0; 
for (int i = 0; i < n - 1; i++) { 
for (int j = i + 1; j < n; j++) { 
if (arr[i] > arr[j]) { 
inv++; 
} 
} 
} 
return inv; 
} 
void printArr(const int arr[], int n) { 
for (int i = 0; i < n; i++) { 
cout << arr[i] << " "; 
} 
cout << endl; 
} 
int main() { 
int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
int n = sizeof(arr) / sizeof(arr[0]); 
cout << "Array:" << endl; 
printArr(arr, n); 
long long inv = countInversions(arr, n); 
cout << "Inversion count: " << inv << endl; 
return 0; 
} 
