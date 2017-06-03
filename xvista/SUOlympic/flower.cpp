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
typedef pair<pii,int> piii;
typedef vector<int> vi;

piii data[100005];
//int G[100005];

struct djnode {
    int parent;
    int rank = 0;
};

djnode djset[100005];

int find(int x) {
    if (djset[x].parent==x) return x;
    return djset[x].parent = find(djset[x].parent);
}

void un(int a,int b) {
    a = find(a);
    b = find(b);
    if (djset[a].rank<djset[b].rank) {
        djset[a].parent = b;
        djset[b].rank++;
    } else {
        djset[b].parent = a;
        djset[a].rank++;
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
        int n; scanf("%d",&n);
        
        for1(i,0,n) {
            scanf("%d%d",&data[i].first.first,&data[i].first.second);
            //G[i] = -1;
            //Glink[i] = -1;
            djset[i].parent = i;
            djset[i].rank = 0;
            data[i].second = i;
        }
        
        sort(data,data+n);

        for1(i,0,n) {
            int cr = data[i].first.first;
            int fi = data[i].second; //first index of that row
            i++;
            while(i<n && data[i].first.first==cr) {
                un(data[i].second,fi);
                i++;
            }
            
            i--;
        }
        
        sort(data,data+n,[](const piii &a,const piii &b) {
            if (a.first.second<b.first.second) return true;
            if (a.first.second>b.first.second) return false;
            
            return a.first.first<b.first.first;
        });
        
        for1(i,0,n) {
            int cc = data[i].first.second;
            int fi = data[i].second; //first index of that row
            i++;
            while(i<n && data[i].first.second==cc) {
                un(data[i].second,fi);
                //cerr<<"aaa "<<i<<' '<<fi<<endl;
                i++;
            }
            
            i--;
        }
        
        set<int> res;
        
        for1(i,0,n) {
            res.insert(find(i));
            //cerr<<i<<"aaa "<<find(i)<<endl;
        }
        
        cout<<(res.size()%2==0?res.size()/2:res.size()/2+1)<<endl;
        
        
    }
	return 0;
}
