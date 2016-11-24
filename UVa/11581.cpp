/**
Normal
1 0 1
0 0 0
1 0 1

f(g)
0 0 0
0 0 0
0 0 0

all 0 in 1 lv -> ans = 0

----------------------------

Normal
1 1 1
1 0 0
0 0 1

f(g)
0 0 1
1 0 0
1 1 0

f(f(g))
1 1 0
1 0 1
0 1 1

f(f(f(g)))
0 1 0
1 0 1
0 1 0

f(f(f(f(g))))
0 0 0
0 0 0
0 0 0

all 0 in 4 lv -> ans = 3

all 0 in n lv -> ans = n-1

solved by try to fill all cell with function f(g)
*/

#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int data[3][3];

int get(int i,int j) {
    if (i<0 || i>=3 || j<0 || j>=3) return 0;
    return data[i][j];
}

void f() {
    int temp[3][3]; //wait for copy
    for1(i,0,3) for1(j,0,3) {
        int sum = get(i-1,j)+get(i+1,j)+get(i,j-1)+get(i,j+1);
        sum &= 1;
        temp[i][j] = sum;
    }
    for1(i,0,3) for1(j,0,3) {
        data[i][j] = temp[i][j];
    }
}

bool isall0() {
    for1(i,0,3) for1(j,0,3) {
        if (data[i][j]) return false;
    }
    return true;
}

void debug() {
    cout<<"DEBUG"<<endl;
    for1(i,0,3) {
        for1(j,0,3) {
            cout<<data[i][j];
        } cout<<endl;
    }
}

deque< vector < vector<int> > > all;
vector < vector<int> > curr(3,vector<int>(3,0));

void bt(int i,int j) {
    if (j>=3) {
        j = 0;
        i++;
    }
    if (i>=3) {
        all.push_back(curr);
        return;
    }
    curr[i][j] = 0;
    bt(i,j+1);
    curr[i][j] = 1;
    bt(i,j+1);
}

void docpy() {
    vector < vector<int> > &v=all[0];
    for1(i,0,3) for1(j,0,3) {
        data[i][j] = v[i][j];
    }
    all.pop_front();
}

int main() {
    int t; cin>>t;
    //bt(0,0);
    while (t--/*!all.empty()*/) {
        int c = -1;

        for1(i,0,3) for1(j,0,3) {
            char x;
            cin>>x; data[i][j]=x-'0';
        }

        //docpy();

        //debug();
        while (!isall0()) {
            f();
            c++;
            //debug();
        }

        cout<<c<<endl;
    }
    return 0;
}
