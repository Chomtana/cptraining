#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n,wbf,lbf;

vector<int> data;

bool process() {
    int countw = 0;
    int countl = 0;
    for1(i,0,data.size()) {
        switch (data[i]) {
        case 1:
            countw++;
            break;
        case 2:
            countl++;
            break;
        }
    }
    if (countw+wbf == n || countl+lbf == n) return true;
    return false;
}

void print() {
    for1(i,0,2*n-1) {
        if (data[i] == 1)
            printf("W ");
        else if (data[i] == 2)
            printf("L ");
    }

}

void bt(int datai) {
    /*if (datai==4) {
        cout<<"aaa";
    }*/
    data[datai] = 1;
    if (!process()) {
        bt(datai+1);
    } else {
        print();
        printf("\n");
    }

    //data[datai] = -1;

    data[datai] = 2;
    if (!process()) {
        bt(datai+1);
        /*if (datai == 2) {
            cout<<"aaa";
        }*/
    } else {
        print();
        printf("\n");
    }

    data[datai] = -1;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	scanf("%d %d %d",&n,&wbf,&lbf);
    data.resize(2*n-1,0);

    bt(0);
	return 0;
}
