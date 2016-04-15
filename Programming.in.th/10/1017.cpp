#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin>>n;
    vector<vector<int> > data(n);
    fill(data.begin(),data.end(),vector<int>(n));
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            cin>>data[i][j];
        }
    }
    
    vector<bool> contains(n*n+1);
    int sum = n*(n*n+1)/2;
    for (int i = 0;i<n;i++) {
        int sumrc = 0;
        int sumcr = 0;
        for (int j = 0;j<n;j++) {
            if (contains[data[i][j]]) { cout << "No"; return 0; }
            sumrc += data[i][j];
            sumcr += data[j][i];
            contains[data[i][j]] = true;
        }
        if (sumrc != sum || sumcr != sum) {
            cout << "No"; return 0;
        }
    }
    
    int sumd1 = 0;
    for (int i = 0;i<n;i++) {
        sumd1 += data[i][i];
    }
    if (sumd1 != sum) { cout << "No"; return 0; }
    
    int sumd2 = 0;
    for (int i = 0;i<n;i++) {
        sumd2 += data[n-1-i][i];
    }
    if (sumd2 != sum) { cout << "No"; return 0; }
    
    cout << "Yes";
    
    return 0;
}