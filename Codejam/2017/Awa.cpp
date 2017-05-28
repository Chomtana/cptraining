#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool allplus(string &s) {
    for1(i,0,s.size()) {
        if(s[i]!='+') {
            return false;
        }
    }
    return true;
}

void flip(char &c) {
    if (c=='+') {
        c = '-';
    } else if (c=='-') {
        c = '+';
    }
}

int countgroup(string &s) {
    int res = s[0]=='+';
    for1(i,1,s.size()) {
        if (s[i]!=s[i-1] && s[i]=='+')
            res++;
    }
    return res;
}

int main2() {
    string s; int k; cin>>s>>k;

    int n = s.size();
    int res = 0;

    int startpoint = 0;

    while (!allplus(s)) {
        //fill perfect
        int pluscount = 0;
        for1(i,startpoint,startpoint+k) {
            if (s[i]=='+') pluscount++;
        }
        for1(i,startpoint,n-k+1) {
            /*bool foundplus = false;
            for1(j,i,i+k) {
                if (s[j]=='+') {
                    foundplus = true;
                    break;
                }
            }*/
            if (i>startpoint) {
                if (s[i-1]=='+') {
                    pluscount--;
                }
                pluscount += s[i+k-1]=='+';
            }
            bool foundplus = pluscount;
            if (!foundplus) {
                res++;
                for1(j,i,i+k) {
                    s[j] = '+';
                }
                pluscount = k;
            }
        }
        cerr<<"STR DBG 1 : "<<s<<endl;

        if (allplus(s)) break;

        //fill not perfect
        bool canfill = false;
        int cgbefore = countgroup(s);
        for1(i,startpoint,n-k+1) {
            bool foundminus = false;
            for1(j,i,i+k) {
                if (s[j]=='-') {
                    foundminus = true;
                    break;
                }
            }

            if (foundminus && (s[i]=='-' || s[i+k-1]=='-')) {
                for1(j,i,i+k) {
                    flip(s[j]);
                }
                int cgafter = countgroup(s);
                if (cgafter<cgbefore) {
                    res++;
                    canfill = true;
                    //startpoint = i;
                    break;
                } else {
                    for1(j,i,i+k) {
                        flip(s[j]);
                    }
                }
            }
        }

        if(!canfill) return -1;
        cerr<<"STR DBG 2 : "<<s<<endl;
    }


    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        cout<<"Case #"<<_<<": ";
        int res = main2();
        if (res==-1) {
            cout<<"IMPOSSIBLE";
        } else {
            cout<<res;
        }
        cout<<endl;
        cerr<<_<<endl;
    }
	return 0;
}
