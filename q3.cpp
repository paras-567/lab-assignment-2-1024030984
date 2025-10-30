#include <iostream> 
using namespace std; 
int findMissingLinear(const int arr[], int size) { 
for (int i = 0; i < size; i++) { 
if (arr[i] != i + 1) { 
return i + 1; 
} 
} 
return size + 1; 
} 
int findMissingBinary(const int arr[], int size) { 
int low = 0; 
int high = size - 1; 
int missing = size + 1; 
while (low <= high) { 
int mid = low + (high - low) / 2; 
         
        if (arr[mid] == mid + 1) { 
            low = mid + 1; 
        } else { 
            missing = mid + 1;  
            high = mid - 1; 
        } 
    } 
    return missing; 
} 
 
int main() { 
    int arr[] = {1, 2, 4, 5, 6, 7, 8}; 
    int size = 7; 
 
    cout << "linear:" << endl; 
    int missingLinear = findMissingLinear(arr, size); 
    cout << "number:" << missingLinear << endl; 
 
    cout << "binary:" << endl; 
    int missingBinary = findMissingBinary(arr, size); 
    cout << "number: " << missingBinary << endl; 
 
    return 0; 
} 
