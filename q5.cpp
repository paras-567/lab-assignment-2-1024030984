#include <iostream> 
 
using namespace std; 
 
const int N = 5; 
 
int getDiag(const int a[], int i, int j) { 
    if (i == j) return a[i]; 
    return 0; 
} 
 
int getTriDiag(const int a[], int i, int j) { 
    int d = i - j; 
    if (d == 0) return a[N - 1 + i]; 
    if (d == -1) return a[i]; 
    if (d == 1) return a[2 * N - 2 + j]; 
    return 0; 
} 
 
int getLower(const int a[], int i, int j) { 
    if (i >= j) return a[i * (i + 1) / 2 + j]; 
    return 0; 
} 
 
int getUpper(const int a[], int i, int j) { 
    if (i <= j) return a[j * (j + 1) / 2 + i]; 
    return 0; 
} 
 
int getSym(const int a[], int i, int j) { 
    if (i >= j) return a[i * (i + 1) / 2 + j]; 
    return a[j * (j + 1) / 2 + i]; 
} 
 
void print(const char msg[], int N, int (*getVal)(const int[], int, int), const 
int a[]) { 
    cout << msg << endl; 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            cout << getVal(a, i, j) << " "; 
        } 
        cout << endl; 
    } 
} 
 
int main() { 
    int a[N] = {10, 20, 30, 40, 50}; 
    int b[13] = {1, 2, 3, 4, 10, 20, 30, 40, 50, 6, 7, 8, 9}; 
    int c[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; 
    int d[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; 
 
    print("Diagonal Matrix", N, getDiag, a); 
    print("Tri-diagonal Matrix", N, getTriDiag, b); 
    print("Lower Triangular Matrix", N, getLower, c); 
    print("Upper Triangular Matrix", N, getUpper, d); 
    print("Symmetric Matrix", N, getSym, c); 
 
    return 0; 
}
