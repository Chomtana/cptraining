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

int count2[1000];
int count3[10000];

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    string s[n];
    for1(i,0,n) cin>>s[i];
    fill(count2,count2+1000,0);
    fill(count3,count3+1000,0);
    for1(i,0,n) {
        for1(j,1,s[i].size()) {
            count2[(s[i][j-1]-'0')*10+(s[i][j]-'0')]++;
        }
        for1(j,2,s[i].size()) {
            count3[(s[i][j-2]-'0')*100+(s[i][j-1]-'0')*10+(s[i][j]-'0')]++;
        }
    }

    int m2 = *max_element(count2,count2+1000);
    int m3 = *max_element(count3,count3+10000);
    for1(i,0,1000) {
        if (count2[i]==m2) printf("%02d ",i);
    }
    cout<<endl;
    for1(i,0,10000) {
        if (count3[i]==m3) printf("%03d ",i);
    }
	return 0;
}
