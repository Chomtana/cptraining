#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;

int n; ll r;
vector<pii> data;

bool inbound(pii a,pii b,pii p) {
    ll minx = min(a.first,b.first);
    ll maxx = max(a.first,b.first);
    ll miny = min(a.second,b.second);
    ll maxy = max(a.second,b.second);
    return (p.first>=minx && p.first<=maxx && p.second>=miny && p.second<=maxy);
}

bool inr(pii a,pii p,int side) {
    pii b = a;
    //a = corner
    switch (side) {
    case 0: //UL
        b.first += r;
        b.second -= r;
        break;
    case 1: //UR
        b.first -= r;
        b.second -= r;
        break;
    case 2: //BL
        b.first += r;
        b.second += r;
        break;
    case 3: //BR
        b.first -= r;
        b.second += r;
        break;
    }
    return inbound(a,b,p);
}

ll main3() {
    ll res = 0;
    vector<int> del;
    for1(i,0,n) {
        if (data[i].first == -1) continue;
        pii &a = data[i];
        ll count = 0;
        //vector<int> points;
        for1(side,0,4) {
            ll sidecount = 0; //0 pork mun ja nub sum tua mun eng duad
            vector<int> points;
            for1(j,0,n) {
                pii &p = data[j];
                if (p.first == -1) continue;
                if (inr(a,p,side)) {
                    sidecount++;
                    points.push_back(j);
                }
            }
            if (sidecount>res) {
                res = sidecount;
                del = points;
            }
        }
        /*if (count>res) {
            res = count;
            del = points;
        }*/
    }
    /*cerr<<"DEBUG: ";
    for1(i,0,del.size()) {
        cerr<<'('<<data[del[i]].first<<','<<data[del[i]].second<<") ";
    }*/
    for1(i,0,del.size()) {
        data[del[i]] = make_pair(-1,-1);
        //data.erase(data.begin()+del[i]); //make index fail
    }
    //cerr<<endl;
    return res;
}

ll main2() {
    cin>>n>>r;
    data.resize(n);
    for1(i,0,n) {
        cin>>data[i].first>>data[i].second;
        //data[i].first = i*i*i*8;
        //data[i].second = i*i*i*4;
    }
    ll res = main3()+main3();
    data.clear();
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	for1(_t,1,t+1) {
        cout<<"Case #"<<_t<<": "<<main2()<<endl;
	}
	return 0;
}
