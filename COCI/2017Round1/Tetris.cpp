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

int nr,nc;
char data[15][15];
bool cc[15][15];
int res[10];

char get(int r,int c) {
    if (r<0||c<0||r>=nr||c>=nc) return '.';
    return data[r][c];
}

#define macro(r,c) get(r,c)==curr
#define macro2(r,c) cc[r][c] = true;

bool re1(int r,int c) {
    char curr = get(r,c);
    //cerr<<"aaa"<<endl;
    if(macro(r+1,c+1) && macro(r+1,c) && macro(r,c+1)) {
        macro2(r,c) macro2(r,c+1)   macro2(r+1,c)   macro2(r+1,c+1)
        return true;
    }
    return false;
}

bool re2(int r,int c) {
    char curr = get(r,c);
    //cerr<<"aaa"<<endl;
    if(macro(r+1,c) && macro(r+2,c) && macro(r+3,c)) {
        macro2(r,c) macro2(r+1,c)   macro2(r+2,c)   macro2(r+3,c)
        return true;
    }
    if(macro(r,c+1) && macro(r,c+2) && macro(r,c+3)) {
        macro2(r,c) macro2(r,c+1)  macro2(r,c+2)  macro2(r,c+3)
        return true;
    }
    return false;
}

bool re3(int r,int c) {
    char curr = get(r,c);
    if(macro(r,c+1) && macro(r+1,c) && macro(r+1,c-1)) {
        macro2(r,c)
        macro2(r,c+1)  macro2(r+1,c)  macro2(r+1,c-1)
        return true;
    }
    if(macro(r+1,c)&&macro(r+1,c+1)&&macro(r+2,c+1)) {
        macro2(r,c)
        macro2(r+1,c) macro2(r+1,c+1) macro2(r+2,c+1)
        return true;
    }

    return false;
}

bool re4(int r,int c) {
    char curr = get(r,c);
    if(macro(r,c+1) && macro(r+1,c+1) && macro(r+1,c+2)) {
        macro2(r,c)
        macro2(r,c+1)  macro2(r+1,c+1)  macro2(r+1,c+2)
        return true;
    }
    if(macro(r+1,c)&&macro(r+1,c-1)&&macro(r+2,c-1)) {
        macro2(r,c)
        macro2(r+1,c) macro2(r+1,c-1) macro2(r+2,c-1)
        return true;
    }

    return false;
}

bool re5(int r,int c) {
    char curr = get(r,c);
    if(macro(r+1,c)&&macro(r+2,c)&&macro(r+1,c-1)) {
        macro2(r,c);
        macro2(r+1,c) macro2(r+2,c) macro2(r+1,c-1)
        return true;
    }
    if(macro(r+1,c)&&macro(r+2,c)&&macro(r+1,c+1)) {
        macro2(r,c);
        macro2(r+1,c) macro2(r+2,c) macro2(r+1,c+1)
        return true;
    }
    if(macro(r+1,c-1)&&macro(r+1,c)&&macro(r+1,c+1)) {
        macro2(r,c);
        macro2(r+1,c-1) macro2(r+1,c) macro2(r+1,c+1)
        return true;
    }
    if(macro(r,c+1)&&macro(r+1,c+1)&&macro(r,c+2)) {
        macro2(r,c);
        macro2(r,c+1) macro2(r+1,c+1) macro2(r,c+2)
        return true;
    }
    return false;
}

int re(int r,int c) {
    if (re1(r,c)) return 1;
    if(re2(r,c)) return 2;
    if(re3(r,c)) return 3;
    if(re4(r,c)) return 4;
    if(re5(r,c)) return 5;
    return -1;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>nr>>nc;
    for1(i,0,nr) {
        scanf("%s",data+i);
    }

    for1(i,0,nr) {
        for1(j,0,nc) {
            if(cc[i][j]||data[i][j]=='.') continue;
            int p = re(i,j);
            if(p!=-1) {
                res[p]++;
            }
        }
    }

    for1(i,1,6) printf("%d\n",res[i]);
	return 0;
}
