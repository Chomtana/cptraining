#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n,k; cin>>n>>k;
    int m; cin>>m;
    map<int, map<int,string> > data;
    for (int i = 0;i<m;i++) {
        int row,col; cin>>row>>col;
        cin >> data[row][col];
    }
    int dir = 1; //NESW -i,+j,+i,-j  R:++ L:--
    int day = 0;
    int pos_i = 1;
    int pos_j = 1;
    while(k != 0) {
        switch (dir) {
            case 0:
                pos_i--;
                break;
            case 1:
                pos_j++;
                break;
            case 2:
                pos_i++;
                break;
            case 3:
                pos_j--;
                break;
        }
        day++;
        if (pos_i > n || pos_j > n || pos_i < 1 || pos_j < 1) {
            k--;
            dir += 2;
            day--;
        }
        if (data[pos_i][pos_j] != "") {
            switch (data[pos_i][pos_j][day]) {
                case 'R':
                    dir++;
                    k--;
                    break;
                case 'L':
                    dir--;
                    k--;
                    break;
            }
        }
        cout << pos_i << " " << pos_j<<"\n";
    }
    cout << day;
    
    return 0;
}