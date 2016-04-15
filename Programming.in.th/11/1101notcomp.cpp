#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct wizard {
    string dir; //direction
    int x;
    int y;
};

int main() {
    int n,k;
    cin >> n >> k;
    int m;
    cin >> m;
    wizard in[m];
    for (int i = 0;i<m;i++) {
        cin >> in[i].x >> in[i].y >> in[i].dir;
    }
    
    int posx = 1;
    int posy = 1;
    int dir = 1; //0 = north 1 = east 2 = south 3 = west
    int count = 0;
    while (true) {
        count++;
        //cout << posx << "\n";
        switch (dir) {
            case 0: posy += 1; break;
            case 1: posx += 1; break;
            case 2: posy -= 1; break;
            case 3: posx -= 1; break;
        }
        if (posx == n || posy == n) {
            break;
        }
    }
    cout << count;
    return 0;
}