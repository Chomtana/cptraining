#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;

int nr,nc,ss;

int SP2i(char c) {
    switch (c) {
        case 'N': return 0; //up
        case 'S': return 2; //down
        case 'L': return 1; //right
        case 'O': return 3; //left
    }
    return -1;
}

void dof(int &r,int &c,int rot) {
    switch (rot) {
    case 0:
        r -= 1;
        if (r<=0) {
            r += 1;
            r = -r;
        }
        break;
    case 1:
        c += 1;
        if (c>=nc+1) {
            c -= 1;
            c = -c;
        }
        break;
    case 2:
        r += 1;
        if (r>=nr+1) {
            r -= 1;
            r = -r;
        }
        break;
    case 3:
        c -= 1;
        //cerr<<c<<endl;
        if (c<=0) {
            c += 1;
            c = -c;
        }

        break;
    }
}

int main() {
    ios::sync_with_stdio(false);

    while (cin>>nr>>nc>>ss,nr != 0) {
        char data[nr+2][nc+2];
        for1(i,0,nr+2) {
            for1(j,0,nc+2) {
                data[i][j] = 0;
            }
        }
        int r,c;
        int rot;
        for1(i,1,nr+1) {
            for1(j,1,nc+1) {
                cin>>data[i][j];
                if (SP2i(data[i][j])!=-1) {
                    r = i;
                    c = j;
                    rot = SP2i(data[i][j]);
                }
            }
        }

        string s; cin>>s;

        int p = 0;

        for1(i,0,s.size()) {
            char cc = s[i];
            switch (cc) {
            case 'D':
                rot += 1;
                if (rot==4) {
                    rot = 0;
                }
                break;
            case 'E':
                rot -= 1;
                if (rot==-1) {
                    rot = 3;
                }
                break;
            case 'F':
                int rold = r;
                int cold = c;
                dof(r,c,rot);

                if (r >= 0 && c>=0) {

                    if (data[r][c] == '*') {
                        p++;
                        data[r][c] = '.';
                    } else if (data[r][c] == '#') {
                        r = rold; c = cold;
                    }
                } else {
                    r = rold;
                    c = cold;
                }
                //cerr<<r<<' '<<c<<endl;
                break;
            }
        }

        cout<<p<<endl;

    }

    return 0;
}
