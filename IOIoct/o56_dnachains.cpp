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

int l,n;
int ne[100005];
int pr[100005];
int Mqs[100005];

bool state = true;
int st[100005];

int curr = 1;

int getpr(int x) {
    if (state) {
        return pr[x];
    } else {
        return ne[x];
    }
}

int getne(int x) {
    if (state) {
        return ne[x];
    } else {
        return pr[x];
    }
}

void setpr(int x,int y) {
    if (state) {
        pr[x] = y;
    } else {
        ne[x] = y;
    }
}

void setne(int x,int y) {
    if (state) {
        ne[x] = y;
    } else {
        pr[x] = y;
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>l>>n;
    for1(i,0,l) {
        int x; scanf("%d",&x);
        if(i>0)Mqs[i] = Mqs[i-1]+x; else Mqs[i]=x;
        for1(j,(i==0?1:Mqs[i-1]+1),Mqs[i]+1) {
            if (j!=Mqs[i]) {
                ne[j]=j+1;
            }
            if(j!=(i==0?1:Mqs[i-1]+1)) {
                pr[j] = j-1;
            }
        }
    }



    for1(i,0,n) {
        char c; scanf(" %c",&c);
        if (c=='B') {
            if (getpr(curr)!=0) {
                curr = getpr(curr);
            }
            if (st[curr]==2) state=false; else if (st[curr]==1) state = true;
            printf("%d\n",curr);
        } else if (c=='F') {
            if (getne(curr)!=0) {
                curr = getne(curr);
            }
            if (st[curr]==2) state=false; else if (st[curr]==1) state = true;
            printf("%d\n",curr);
        } else {
            int x; scanf("%d",&x);
            if (getne(curr)!=0) {
                st[getne(curr)] = 0; //crit test case : if remove next element that start reverse
                                    //-> insert removed dna in normal order
                                    //-> if traversal to end of dna then it will trigger unexpected reverse in end of dna
                                    //(make it cannot go back because of inverse command)
                setpr(getne(curr),0);
            }
            setne(curr,x);

            if (state) {
                if (ne[x]==0) {
                    st[x] = 2;
                    if (state) st[curr]=1; else st[curr]=2;
                    state = false;

                } else {
                    st[x] = 0;
                }
            } else {
                if (pr[x]==0) {
                    st[x] = 1;
                    if (state) st[curr]=1; else st[curr]=2;
                    state = true;
                } else {
                    st[x] = 0;
                }
            }

            setpr(x,curr);
            curr = x;
            printf("%d\n",curr);
        }
    }

	return 0;
}
