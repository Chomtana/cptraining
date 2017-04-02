#include <bits/stdc++.h>
//#include <unordered_map>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

class info {
    public:
    int id,type,price,stock;
};

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
	unordered_map<int,info> data(n);
	for1(i,0,n) {
	    int id;
	    cin >> id;
	    data[id].id = id;
	    cin>>data[id].type>>data[id].price>>data[id].stock;
	}
	int k; cin>>k;
	while (k--) {
        int a,b,c; cin>>a>>b>>c;
        vector<bool> type(4,false);
        type[data[a].type] = true;
        type[data[b].type] = true;
        type[data[c].type] = true;
        if (!type[1] || !type[2] || !type[3]) {
            cout<<"invalid order"<<endl;
            continue;
        }
        if (data[a].stock <= 0) {
            cout<<"out of stock"<<endl;
            continue;
        }
        if (data[b].stock <= 0) {
            cout<<"out of stock"<<endl;
            continue;
        }
        if (data[c].stock <= 0) {
            cout<<"out of stock"<<endl;
            continue;
        }
        data[a].stock--;
        data[b].stock--;
        data[c].stock--;
        cout<<data[a].price+data[b].price+data[c].price<<endl;
	}
	return 0;
}
