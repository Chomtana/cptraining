#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int t[3][1005][1005];
int qs[3][1005][1005];

int query(int type,int sr,int sc,int er,int ec) {
    int value = qs[type][er][ec];
    if (i>0 && j>0) {
        value += qs[type][sr-1][sc-1];
    }
    if (i>0) {
        value -= qs[type][sr-1][ec];
    }
    if (j>0) {
        value -= qs[type][er][sc-1];
    }
    return value;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,k; cin>>n>>k;
    for1(i,0,n) { for1(j,0,n) {
        scanf("%d",&t[0][i][j]);
    } }
    for1(i,0,n) { for1(j,0,n) {
        scanf("%d",&t[1][i][j]);
    } }
    for1(i,0,n) { for1(j,0,n) {
        scanf("%d",&t[2][i][j]);
    } }

    qs[0][0][0] = t[0][0][0];
    qs[1][0][0] = t[1][0][0];
    qs[2][0][0] = t[2][0][0];
    for1(j,1,n) {
        qs[0][0][j] = qs[0][0][j-1]+t[0][0][j];
        qs[1][0][j] = qs[1][0][j-1]+t[1][0][j];
        qs[2][0][j] = qs[2][0][j-1]+t[2][0][j];
    }
    for1(i,1,n) {
        qs[0][i][0] = qs[0][i-1][0]+t[0][i][0];
        qs[1][i][0] = qs[1][i-1][0]+t[1][i][0];
        qs[2][i][0] = qs[2][i-1][0]+t[2][i][0];

        for1(j,1,n) {
            qs[0][i][j] = qs[0][i-1][j]+qs[0][i][j-1]-qs[0][i-1][j-1]+t[0][i][j];
            qs[1][i][j] = qs[1][i-1][j]+qs[1][i][j-1]-qs[1][i-1][j-1]+t[1][i][j];
            qs[2][i][j] = qs[2][i-1][j]+qs[2][i][j-1]-qs[2][i-1][j-1]+t[2][i][j];
        }
    }

    /*for1(i,0,n) {
        for1(j,0,n) {
            cerr<<qs1[i][j]<<' ';
        }
        cerr<<endl;
    }cerr<<endl;
    for1(i,0,n) {
        for1(j,0,n) {
            cerr<<qs2[i][j]<<' ';
        }
        cerr<<endl;
    }cerr<<endl;
    for1(i,0,n) {
        for1(j,0,n) {
            cerr<<qs3[i][j]<<' ';
        }
        cerr<<endl;
    }*/

    int order[] = {0,1,2}; //order of selection 3! brute force
    do {
        int s1r,s1c,s2r,s2c,s3r,s3c;
        int s1max = 0;
        //s1
        for1(i,0,n-k+1) {
            for1(j,0,n-k+1) {
                int value = query(order[0],i,j,i+k-1,j+k-1);
                if (value>s1max) {
                    s1max = value;

                }
            }
        }
    } while (next_permutation(order,order+3));
	return 0;
}
