#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    long long result = 0;
    for (int i = 0;i<n;i++) {
        long long in;
        cin >> in;
        result += ((n-i)%2553)*((1+n-i)%2553)/2*(in%2553);
        result %= 2553;
    }
    
    cout << result%2553;
    
    return 0;
}