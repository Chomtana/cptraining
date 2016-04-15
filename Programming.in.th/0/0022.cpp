#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string buildtext (int l,int pos) {
    string result = "";
    for (int i = 0;i<l;i++) {
        if (i == pos || i == l-pos-1) {
            result += "*";
        } else {
            result += "_";
        }
    }
    return result;
}

int main() {
    int n;
    int pos = 0;
    int l = 0;
    bool pos0 = true;
    bool posplus = false;
    scanf("%d",&n);
    if (n%2 == 0) {
        pos = (n-2)/2;
    } else {
        pos = ((n-2)/2)+1;
        pos0 = false;
    }
    l = (pos*2)+1;
    for (int i = 0;i<n;i++) {
        if (pos == 0) {
            if (pos0) {
                pos0 = false;
            } else {
                posplus = true;
            }
        }
        cout << buildtext(l,pos) << "\n";
        if (posplus) {
            pos++;
        } else {
            if (pos != 0) {
                pos--;
            }
        }
    }
    return 0;
}

