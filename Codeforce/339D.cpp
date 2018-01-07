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

int n,m;
int data[150005];
int sm[600005];

int fusion(int a,int b,int s,int e) {
    if ((int)round(log2(e-s+1))%2==0) {
        return a^b;
    } else return a|b;
}

void build(int c,int s,int e) {
    if(s==e) {
        sm[c] = data[s];
    } else {
        int mid = (s+e)/2;
        build(2*c,s,mid);
        build(2*c+1,mid+1,e);
        sm[c] = fusion(sm[2*c],sm[2*c+1],s,e);
    }
}

void update(int c,int s,int e,int pos,int val) {
    if (s==e) {
        data[pos] = val;
        sm[c] = val;
        //cerr<<"aaa"<<endl;
    } else {
        int mid = (s+e)/2;
        if (pos<=mid) update(2*c,s,mid,pos,val);
        if (pos>mid) update(2*c+1,mid+1,e,pos,val);
        sm[c] = fusion(sm[2*c],sm[2*c+1],s,e);
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    for1(i,0,(1<<n)) scanf("%d",data+i);

    build(1,0,(1<<n)-1);

    //cerr<<sm[1]<<endl;
    //for1(i,1,8) cerr<<sm[i]<<' '; cerr<<endl;

    while(m--) {
        int a,b; scanf("%d%d",&a,&b);
        a--;
        update(1,0,(1<<n)-1,a,b);
        //for1(i,1,8) cerr<<sm[i]<<' '; cerr<<endl;
        printf("%d\n",sm[1]);
    }
	return 0;
}
