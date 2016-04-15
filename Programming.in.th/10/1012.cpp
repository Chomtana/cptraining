#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin>>n;
    double sum = 0;
    while (n--) {
        int a,b,c,d,e; cin>>a>>b>>c>>d>>e;
        sum += a*8;
        sum += b*6;
        sum += c*4;
        sum += d*2;
        sum += e;
    }
    cout << ceil(sum/8);
    return 0;
}

//testcase observation