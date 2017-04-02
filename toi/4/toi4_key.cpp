#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

char mid(char a,char b,char c) {
    int mi = min(min(a,b),c);
    int ma = max(max(a,b),c);
    if ((mi==a && ma==b) || (ma==a && mi==b)) return c;
    else if ((mi==b && ma==c) || (ma==b && mi==c)) return a;
    else if ((mi==a && ma==c) || (ma==a && mi==c)) return b;
    return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int l,k; scanf("%d %d",&l,&k);
    char top[l+10];
    char bottom[l+10];
    char key[k+10];
    scanf("%s %s %s",top,bottom,key);
    int curr = 1-k;
    while (curr<l) {
        for1(i,curr,curr+k) {
            if (i<0 || i>=l) continue;
            key[i-curr] = mid(key[i-curr],top[i],bottom[i]);
        }
        curr++;
    }
    printf("%s",key);
	return 0;
}
