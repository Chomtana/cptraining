#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int data[n];
    for (int i = 1;i<=n;i++) {
        data[i-1] = i;
    }
    int exn; //Exception length
    cin >> exn;
    map<int,bool> exdata; //Exception data ... bool default = false
    for (int i = 0;i<exn;i++) {
        int _exdata;
        cin >> _exdata;
        exdata[_exdata] = true;
    }
    do {
        for (int i = 0;i<n;i++) {
            if (!exdata[data[0]]) {
                cout << data[i] << " ";
            }
        }
        if (!exdata[data[0]]) cout << "\n";
    } while ( next_permutation(data,data+n) );
    return 0;
}