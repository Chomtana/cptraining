#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define for3(a,b,c) for((a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<int> data;

int n;

bool isprime[50];

bool process() {
    bool has[n+1];
    for1(i,0,n+1) has[i] = false;
    for1(i,0,n) {
        if (has[data[i]]) return false;
        has[data[i]] = true;
    }
    int i;
    for3(i,0,n-1) {
        if (data[i+1]==-1) break;
        int sum = data[i]+data[i+1];
        if (!isprime[sum]) {
            return false;
        }
    }
    return true;
}

void print() {
    for1(i,0,n) {
        cout<<data[i];
        if (i<n-1) {
            cout<<' ';
        }
    }
    cout<<endl;
}

void bt(int datai) {
    //cout<<datai<<endl;
    if (datai>=n) {
        if (isprime[data[n-1]+data[0]]) {
            print();
        }
        return;
    }

    for1(i,2,n+1) {
        data[datai] = i;
        //print();
        if (process()) {
            bt(datai+1);
        }
    }

    data[datai] = -1;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

	//init isprime
	for1(i,0,50) isprime[i] = false;
	isprime[2] = true;
	isprime[3] = true;
	isprime[5] = true;
	isprime[7] = true;
	isprime[11] = true;
	isprime[13] = true;
	isprime[17] = true;
	isprime[19] = true;
	isprime[23] = true;
	isprime[29] = true;
	isprime[31] = true;
	isprime[37] = true;
	isprime[41] = true;
	isprime[43] = true;
	isprime[47] = true;

	int t = 1;
    while(cin>>n) {
        if (t>1) {
            cout<<endl;
        }
        cout<<"Case "<<t<<":"<<endl;
        data.resize(n,-1);
        data[0] = 1;

        bt(1);

        data.clear();

        t++;
    }
	return 0;
}
