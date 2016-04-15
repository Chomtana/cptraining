#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    long long a[n];
    long long dp_k[n];
    long long dp_j[n];
    long long dp_i[n];
    for (int i = 0;i<n;i++) {
        cin >> a[i];
    }
    
    //1st step
    dp_k[0] = a[0];
    for (int k = 1;k<n;k++) {
        dp_k[k] = dp_k[k-1]+a[k]%2553;
        dp_k[k] %= 2553;
    }
    
    //2nd step
    dp_j[0] = a[0];
    for (int j = 1;j<n;j++) {
        dp_j[j] = dp_j[j-1]+dp_k[j]%2553;
        dp_j[j] %= 2553;
    }
    
    //3rd step
    dp_i[0] = a[0];
    for (int i = 1;i<n;i++) {
        dp_i[i] = dp_i[i-1]%2553+dp_j[i];
    }
    
    /*int sum = 0;
    for (int i = 0;i<n;i++) {
        sum += dp_i[i];
        cout << dp_i[i] << " ";
    }*/
    //cout << sum;
    
    cout << dp_i[n-1]%2553;
    
    //cout << dp_k[n-1];
}