#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n;
    int in[1001];
    scanf("%d",&n);
    for (int i = 0;i<n;i++) {
        scanf("%d",&n);
    }
    sort(in,in+n);
    for (int i = 0;i < n;i++) {
        cout << in[i] << "\n";
    }
    return 0;
}

