#include <iostream> 
#include <cstring> 
#include <algorithm> 
#include <cctype> 
 
using namespace std; 
 
void concatStr(char d[], const char s[]) { 
    strcat(d, s); 
} 
 
void reverseStr(char s[]) { 
    reverse(s, s + strlen(s)); 
} 
 
void deleteVowels(char s[]) { 
    char* w = s; 
    for (char* r = s; *r; r++) { 
        char l = tolower(*r); 
        if (!(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')) { 
            *w++ = *r; 
        } 
    } 
    *w = '\0'; 
} 
 
void sortArr(char arr[][10], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (strcmp(arr[i], arr[j]) > 0) { 
                char temp[10]; 
                strcpy(temp, arr[i]); 
                strcpy(arr[i], arr[j]); 
                strcpy(arr[j], temp); 
            } 
        } 
    } 
} 
 
char toLowerChar(char c) { 
    return tolower(c); 
} 
 
int main() { 
    cout << "Concatenate Strings" << endl; 
    char s1[50] = "Hello"; 
    char s2[] = "World"; 
    concatStr(s1, s2); 
    cout << "Original: " << "Hello, " << s2 << endl; 
    cout << "Result: " << s1 << endl; 
 
    cout << endl << "Reverse String" << endl; 
    char s3[] = "Alphabet"; 
    reverseStr(s3); 
    cout << "Original: Alphabet" << endl; 
    cout << "Result: " << s3 << endl; 
 
    cout << endl << "Delete Vowels" << endl; 
    char s4[] = "Programming"; 
    deleteVowels(s4); 
    cout << "Original: Programming" << endl; 
    cout << "Result: " << s4 << endl; 
 
    cout << endl << "Sort Array of Strings" << endl; 
    char arr[4][10] = {"zebra", "apple", "banana", "cat"}; 
    int n = 4; 
    cout << "Before sorting: " << arr[0] << ", " << arr[1] << ", " << arr[2] << 
", " << arr[3] << endl; 
    sortArr(arr, n); 
    cout << "After sorting: " << arr[0] << ", " << arr[1] << ", " << arr[2] << ", 
" << arr[3] << endl; 
 
    cout << endl << "Uppercase to Lowercase Character" << endl; 
    char uc = 'G'; 
    char lc = toLowerChar(uc); 
    cout << "Original: " << uc << endl; 
    cout << "Result: " << lc << endl; 
 
    return 0; 
}
