#include <iostream>
#include <math>

using namespace std;

struct circle {
    int x,y,r;
};

int main() {
    int n;
    cin >> n;
    circle in[n];
    for (int i = 0;i<n;i++) {
        cin >> in[i].x >> in[i].y >> in[i].r;
    }
    
    for (int i = 0;i<n;i++) {
        for (int i2 = i+1;i2<n;i2++) {
            if ( abs(in[i].x-in[i2].x)* )
        }
    }
    return 0;
}