#include <iostream>

using namespace std;

#define N (1<<18)
#define A 1222333444
int t[2*N];

void muuta(int k, int x) {
    k += N;
    t[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = min(t[2*k],t[2*k+1]);
    }
}

int pienin(int a, int b) {
    a += N; b += N;
    int p = A;
    while (a <= b) {
        if (a%2 == 1) p = min(p,t[a++]);
        if (b%2 == 0) p = min(p,t[b--]);
        a /= 2; b /= 2;
    }
    return p;
}

int n, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < 2*N; i++) t[i] = A;
    while (q--) {
        string x;
        int a, b;
        cin >> x >> a >> b;
        if (x == "M") {
            muuta(b,a);
        } else {
            if (t[b+N] <= a) {
                cout << b << "\n";
                continue;
            }
            int k = b;
            for (int z = (n-k)/2+1; z >= 1; z /= 2) {
                while (k+z <= n && pienin(k,k+z) > a) k += z;
            }
            if (k == n) cout << "-1\n";
            else cout << k+1 << "\n";
        }
    }
}
