#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int data[3];
    for(int i = 0;i<3;i++) cin>>data[i];
    int x = max_element(data,data+3)-data;

    if (data[0]+data[1]+data[2] != 100) {
        cout<<"BUG"; return 0;
    }

    //bool multi = false;
    for(int i = 0;i<3;i++) {
        if (x==i) continue;
        if (data[x]==data[i]) {
            cout<<"I DON'T KNOW"; return 0;
        }
    }
    switch(x) {
    case 0:
        cout<<"PAPER"; break;
    case 1:
        cout<<"SCISSORS"; break;
    case 2:
        cout<<"ROCK"; break;
    }
    return 0;
}
