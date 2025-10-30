#include <iostream> 
using namespace std; 
int countDistinct(const int arr[], int n) { 
int d = 0; 
    for (int i = 0; i < n; i++) { 
        bool dup = false; 
        for (int j = 0; j < i; j++) { 
            if (arr[i] == arr[j]) { 
                dup = true; 
                break; 
            } 
        } 
        if (!dup) { 
            d++; 
        } 
    } 
    return d; 
} 
 
void printArr(const int arr[], int n) { 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
} 
 
int main() { 
    int arr[] = {10, 20, 10, 30, 20, 40, 50, 50}; 
    int n = 8; 
     
    cout << "Array:" << endl; 
    printArr(arr, n); 
 
    int dist = countDistinct(arr, n); 
     
    cout << "Distinct count: " << dist << endl; 
 
    return 0; 
} 
