#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool compfunc(pii a,pii b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;

    return a.second > b.second;
}

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
	//sort x
	//dp find max(...,end) of y;
    int n; scanf("%d",&n);//cin>>n;
    vector<pii> data(n);

    for1(i,0,n) {
        //cin>>data[i].first>>data[i].second;
        scanf("%d %d",&data[i].first,&data[i].second);
    }

    sort(all(data),compfunc);

    /*vector<int> maxdp(n,-1);
    maxdp[n-1] = data[n-1].second;
    for(int i = n-2;i>=0;i--) {
        maxdp[i] = max(maxdp[i+1],data[i].second);
    }*/


    //set<pii> res;

    /*for1(i,0,n-1) {
        cout<<"aaa"<<i<<' '<<maxdp[i]<<endl;
    }*/

    vector<pii> res;

    int j = 0;

    int currmax = data[n-1].second;
    //cout<<data[n-1].first<<' '<<data[n-1].second<<endl;
    //printf("%d %d\n",data[n-1].first,data[n-1].second);
    res.push_back(make_pair(data[n-1].first,data[n-1].second));
    for(int i = n-2;i>=0;i--) {
        if (data[i].first == data[n-1].first) {
            //cout<<data[i].first<<' '<<data[i].second<<endl;
            //printf("%d %d\n",data[i].first,data[i].second);
            res.push_back(make_pair(data[i].first,data[i].second));
            continue;
        }
        if (data[i].first != data[i+1].first) {
            currmax = max(currmax,data[i+1].second);

        }
        if (currmax<=data[i].second) {
            //res.insert(data[i]);
            //cout<<data[i].first<<' '<<data[i].second<<endl;
            //printf("%d %d\n",data[i].first,data[i].second);
            res.push_back(make_pair(data[i].first,data[i].second));
        }
    }
    //res.insert(data[n-1]);
    //cout<<data[n-1].first<<' '<<data[n-1].second;
    /*for(auto it = res.begin();it != res.end(); it++) {
        cout<<it->first<<' '<<it->second<<endl;
    }*/

    sort(all(res),compfunc);

    for1(i,0,res.size()) {
        printf("%d %d\n",res[i].first,res[i].second);
    }

	return 0;
}
