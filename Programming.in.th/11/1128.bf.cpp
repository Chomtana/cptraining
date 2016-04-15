#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0;i<n;i++) {
        cin >> a[i];
    }
    
    int val = 0;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<=i;j++) {
            for (int k = 0;k<=j;k++) {
                val += a[k];
            }
        }
    }
    
    cout << val%2553;
}