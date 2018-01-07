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

int data[105][105];
int f[105][105];
int ff[105][105];
int target;

int nr,nc;

void printans() {
    puts("Answer found !!!");
    for1(i,0,nr) {
        for1(j,0,nc) {
            printf("%d ",f[i][j]);
        }
        puts("");
    }
    puts("");
}

void addff() {
    for1(i,0,nr) {
        for1(j,0,nc) {
            ff[i][j] += f[i][j];
        }
    }
}

bool recur(int cr,int cc,int sum) {
    //cerr<<cr<<' '<<cc<<' '<<sum<<endl;

    if (sum>target) return false;
    if (sum==target) {
        //printans();
        addff();
        return true;

    }

    if (cr>=nr) {
        if (sum==target) {
            //printans();
            addff();
            return true;
        }
        return false;
    }
    if (cc>=nc) {
        return recur(cr+1,0,sum);
    }

    bool ans = false;

    f[cr][cc] = 0;
    ans |= recur(cr,cc+1,sum);

    //if (ans) return true;

    f[cr][cc] = 1;
    ans |= recur(cr,cc+1,sum+data[cr][cc]);

    f[cr][cc] = 0;

    return ans;

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>nr>>nc;
    //memset(f,-1,sizeof(f));
    for1(i,0,nr) {
        for1(j,0,nc) {
            scanf("%d",&data[i][j]);
        }
    }

    cin>>target;

    recur(0,0,0);

    for1(i,0,nr) {
        for1(j,0,nc) {
            printf("%d ",ff[i][j]);
        }
        printf("\n");
    }
	return 0;
}
