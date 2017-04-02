#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int limit = 0;
int n = 0;

vector<int> data1;
vector<int> data2;



//if you don't sure whether do from bottom to top and top to bottom get same result -> you must do dp from final step to first step
//if you do this you will get result from first step to final step
pii dp(int select1,int select2,bool selected1) {
    //if (select1) {
    pii a,b;
    a = mp(1E9,0);
    b = mp(1E9,0);
    if (selected1) {
        if (select1-1>=0) {
            a = dp(select1-1,select2,true);
            b = dp(select1-1,select2,false);
        } else if (select1-1==-1) {
            b = dp(select1-1,select2,false);
        }
    } else {
        if (select2-1>=0) {
            a = dp(select1,select2-1,true);
            b = dp(select1,select2-1,false);
        } else if (select2-1==-1) {
            a = dp(select1,select2-1,true);
        }
    }
    /*if (select1-1>=-1) {
        a = dp(select1-1,select2,true);
    }
    if (select2-1>=-1) {
        b = dp(select1,select2-1,false);
    }*/



    if (select1==-1 && select2==-1) {
        return mp(1,0);
    }

    /*if (select1==0) {
        //only select 1 end isn't first step
        return mp(1E9,1E9);
    }

    if (select2==0) {
        //only select 2 end isn't first step
        return mp(1E9,1E9);
    }*/

    pii minprev = min(a,b);

    int r = minprev.second;

    if (selected1) {
        r += data1[select1];
    } else {
        r += data2[select2];
    }

    if (r>limit) {
        minprev.first++;
        if (selected1) {
            r = data1[select1];
        } else {
            r = data2[select2];
        }
    }

    return mp(minprev.first,r);
}



int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    scanf("%d %d",&limit,&n);
    data1.resize(n); data2.resize(n);
    for1(i,0,n) scanf("%d",&data1[i]);
    for1(i,0,n) scanf("%d",&data2[i]);

    //if you don't sure whether do from bottom to top and top to bottom get same result -> you must do dp from final step to first step
    pii a = dp(n-1,n-1,true);
    pii b = dp(n-1,n-1,false);

    pii res = min(a,b);

    cout<<res.first<<endl<<res.second;
	return 0;
}
