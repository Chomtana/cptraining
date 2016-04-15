#include <iostream>
#include <math.h>

using namespace std;

int main() {
    float totalprice = 0;
    int n,m;
    cin >> n >> m;
    int l,k;
    cin >> l >> k;
    int c;
    cin >> c;
    for (int row = 0;row<n;row++) {
        for (int col = 0;col<m;col++) {
            int i;
            cin >> i;
            totalprice += i;
        }
    }
    totalprice = ceil(((l*k*c)+totalprice)/c);
    cout << (int)totalprice;
    return 0;
}