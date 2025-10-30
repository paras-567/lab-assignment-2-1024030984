#include <iostream> 
#include <algorithm> 
#include <cstring> 
 
using namespace std; 
 
const int MAXT = 15; 
const int MAXD = 5; 
 
struct T { 
    int r, c, v; 
}; 
 
void printT(const char msg[], const T m[]) { 
    cout << msg << endl; 
    for (int i = 0; i <= m[0].v; i++) { 
        cout << m[i].r << " " << m[i].c << " " << m[i].v << endl; 
    } 
} 
 
void transposeM(const T m[], T res[]) { 
    int R = m[0].r; 
    int C = m[0].c; 
    int t = m[0].v; 
    res[0].r = C; 
    res[0].c = R; 
    res[0].v = t; 
 
    if (t <= 0) return; 
 
    int term = 1; 
    for (int j = 0; j < C; j++) { 
        for (int i = 1; i <= t; i++) { 
            if (m[i].c == j) { 
                res[term].r = m[i].c; 
                res[term].c = m[i].r; 
                res[term].v = m[i].v; 
                term++; 
            } 
        } 
    } 
} 
 
void addM(const T m1[], const T m2[], T res[]) { 
    if (m1[0].r != m2[0].r || m1[0].c != m2[0].c) { 
        res[0].v = 0; 
        return; 
    } 
 
    int i = 1, j = 1, k = 1; 
    res[0].r = m1[0].r; 
    res[0].c = m1[0].c; 
 
    while (i <= m1[0].v && j <= m2[0].v) { 
        if (m1[i].r < m2[j].r || (m1[i].r == m2[j].r && m1[i].c < m2[j].c)) { 
            res[k++] = m1[i++]; 
        } else if (m1[i].r > m2[j].r || (m1[i].r == m2[j].r && m1[i].c > 
m2[j].c)) { 
            res[k++] = m2[j++]; 
        } else { 
            int sum = m1[i].v + m2[j].v; 
            if (sum != 0) { 
                res[k].r = m1[i].r; 
                res[k].c = m1[i].c; 
                res[k++].v = sum; 
            } 
            i++; j++; 
        } 
    } 
 
    while (i <= m1[0].v) res[k++] = m1[i++]; 
    while (j <= m2[0].v) res[k++] = m2[j++]; 
 
    res[0].v = k - 1; 
} 
 
void multiplyM(const T m1[], const T m2[], T res[]) { 
    if (m1[0].c != m2[0].r) { 
        res[0].v = 0; 
        return; 
    } 
 
    int R1 = m1[0].r; 
    int C2 = m2[0].c; 
     
    int tmp[MAXD][MAXD] = {0}; 
 
    for (int i = 1; i <= m1[0].v; i++) { 
        for (int j = 1; j <= m2[0].v; j++) { 
            if (m1[i].c == m2[j].r) { 
                if (m1[i].r < MAXD && m2[j].c < MAXD) { 
                     tmp[m1[i].r][m2[j].c] += m1[i].v * m2[j].v; 
                } 
            } 
        } 
    } 
 
    res[0].r = R1; 
    res[0].c = C2; 
    int k = 1; 
 
    for (int i = 0; i < R1; i++) { 
        for (int j = 0; j < C2; j++) { 
            if (tmp[i][j] != 0 && k <= MAXT * MAXD) { 
                res[k].r = i; 
                res[k].c = j; 
                res[k].v = tmp[i][j]; 
                k++; 
            } 
        } 
    } 
    res[0].v = k - 1; 
} 
 
int main() { 
    T a[MAXT + 1] = { 
        {3, 4, 4},  
        {0, 0, 10},  
        {1, 2, 20},  
        {2, 0, 30},  
        {2, 3, 40} 
    }; 
 
    T b[MAXT + 1] = { 
        {3, 4, 3},  
        {0, 0, 5},  
        {1, 2, 10},  
        {2, 3, 50} 
    }; 
     
    T c[MAXT + 1] = { 
        {4, 3, 4}, 
        {0, 1, 1}, 
        {1, 0, 2}, 
        {2, 2, 3}, 
        {3, 1, 4} 
    }; 
     
    T res[MAXT * MAXD + 1]; 
 
    cout << "A (R C V):" << endl; 
    printT("A", a); 
 
    cout << "B (R C V):" << endl; 
    printT("B", b); 
 
    cout << "C (R C V):" << endl; 
    printT("C", c); 
 
     
    transposeM(a, res); 
    printT("Transpose of A", res); 
 
     
    addM(a, b, res); 
    printT("Addition of A and B", res); 
 
    
multiplyM(a, c, res); 
printT("Multiplication of A and C", res); 
return 0; 
} 
