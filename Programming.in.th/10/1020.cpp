#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char in[202];
    scanf("%s",&in);
    bool pa = true;
    bool doublepa = true;
    int len = 0;
    if (strlen(in)%2 == 0) {
        len = strlen(in)/2;
    } else {
        len = (strlen(in)/2)+1;
    }        
    for (int i = 0;i<len;i++) {
        in[i] = tolower(in[i]);
        in[strlen(in)-i-1] = tolower(in[strlen(in)-i-1]);
        if (in[i] != in[strlen(in)-i-1]) {
            pa = false;
            break;
        }    
    }
    for (int i = 0;i<len/2;i++) {
        if ((in[i] != in[(strlen(in))/2-i-1]) && (in[len+i] != in[strlen(in)-i-1])) {
            doublepa = false;
            break;
        }    
    }    
    if (pa) {
        if (doublepa) {
            cout << "Double Palindrome";
        } else {
            cout << "Palindrome";
        }        
    } else {
        cout << "No";
    }    
    //system("pause");   
    return 0;
}

