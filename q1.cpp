#include <iostream> 
 
using namespace std; 
 
int binarySearch(const int arr[], int size, int target) { 
    int low = 0; 
    int high = size - 1; 
 
    while (low <= high) { 
        int mid = low + (high - low) / 2; 
        if (arr[mid] == target) { 
            return mid; 
        } else if (arr[mid] < target) { 
            low = mid + 1; 
        } else { 
            high = mid - 1; 
        } 
    } 
    return -1; 
} 
 
int main() { 
    int sortedArr[] = {1, 7, 8, 15, 16, 23, 35}; 
    int size = 7; 
    int targetVal = 23; 
    int result = binarySearch(sortedArr, size, targetVal); 
 
    if (result != -1) { 
        cout << "Element found at index: " << result << endl; 
    } else { 
        cout << "Element not found in the array." << endl; 
    } 
 
    return 0; 
}
