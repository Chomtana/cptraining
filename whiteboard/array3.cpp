#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int randomx[100];
	int randomy[100];
	for1(i,0,100) {
        randomx[i] = i+1;
        randomy[i] = i+1;
	}
	srand(time(0));
	random_shuffle(randomx,randomx+100);
	random_shuffle(randomy,randomy+100);
    int x[20];
    int y[20];
    int xy[40];
    for1(i,0,40) xy[i]=1E9;
	for1(i,0,20) {
        x[i] = randomx[i];
        y[i] = randomy[i];
	}

    int count = 0;

    for1(i,0,20) {
        for1(j,0,20) {
            if (y[j]==x[i]) {
                y[j] = 1E9;
                x[i] = 1E9;
                count++;
                break;
            }
        }
    }

    cout<<"count of y in x : "<<count<<endl;

    for1(i,0,20) {
        xy[i] = x[i];
        xy[20+i] = y[i];
    }

	sort(xy,xy+40,greater<int>());

	cout<<"remove duplicate element and sort : ";

    for1(i,0,40) {
        if (xy[i] != 1E9) {
            cout<<xy[i]<<' ';
        }
    }
	return 0;
}
