//Time limit because of use two unordered_map ... can only use one

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;

class Hasher {
    public:
    size_t operator () (const pii &data) const {
        return ((data.first+data.second)*(data.first+data.second))%1000000;
    }
};

void print(pair<pii,pii> &p) {
    printf("%lld %lld\n%lld %lld\n",p.first.first,p.first.second,p.second.first,p.second.second);
    //cout<<p.first.first<<' '<<p.first.second<<' '<<p.second.first<<' '<<p.second.second<<endl;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    ll xt,yt; scanf("%lld %lld",&xt,&yt); //cin>>xt>>yt;
    int n; scanf("%d",&n);
    //cout<<xt<<' '<<yt<<' '<<n<<endl;
    pii data1[n]; for1(i,0,n) /*cin>>data1[i].first>>data1[i].second;*/scanf(" %lld %lld",&data1[i].first,&data1[i].second);
    pii data2[n]; for1(i,0,n) /*cin>>data2[i].first>>data2[i].second;*/scanf(" %lld %lld",&data2[i].first,&data2[i].second);
    pii data3[n]; for1(i,0,n) /*cin>>data3[i].first>>data3[i].second;*/scanf(" %lld %lld",&data3[i].first,&data3[i].second);
    pii data4[n]; for1(i,0,n) /*cin>>data4[i].first>>data4[i].second;*/scanf(" %lld %lld",&data4[i].first,&data4[i].second);

    //for1(i,0,n) scanf("")

    vector<pii> sum12;
    unordered_map<pii,pair<pii,pii>,Hasher> res12(1000000);

    for1(i,0,n) {
        for1(j,0,n) {
            int sumx = data1[i].first+data2[j].first;
            int sumy = data1[i].second+data2[j].second;
            sum12.push_back(mp(sumx,sumy));
            res12[mp(sumx,sumy)] = mp(data1[i],data2[j]);
            //pair<pii,pii> dbg = mp(mp(data1[i].first,data1[i].second),mp(data2[j].first,data2[j].second));
            //print(dbg);
            //cout<<data1[i].first<<' '<<data1[i].second<<' '<<data2[j].first<<' '<<data2[j].second<<endl;
        }
    }

    vector<pii> sum34;
    unordered_map<pii,pair<pii,pii>,Hasher> res34(1000000);

    for1(i,0,n) {
        for1(j,0,n) {
            int sumx = data3[i].first+data4[j].first;
            int sumy = data3[i].second+data4[j].second;
            sum34.push_back(mp(sumx,sumy));
            res34[mp(sumx,sumy)] = mp(data3[i],data4[j]);

        }
    }

    for1(i,0,sum12.size()) {
        for1(j,0,sum34.size()) {
            int sumx = sum12[i].first+sum34[j].first;
            int sumy = sum12[i].second+sum34[j].second;
            if (sumx==xt && sumy==yt) {
                //print answer
                pair<pii,pii> firstpart = res12[sum12[i]];
                pair<pii,pii> secondpart = res34[sum34[j]];
                //printf("%d %d\n%d %d\n%d %d\n%d %d",firstpart.first.first,firstpart.first.second,firstpart.second.first,firstpart.second.second,secondpart.first.first,secondpart.first.second,secondpart.second.first,secondpart.second.second);
                print(firstpart);
                print(secondpart);
                //cout<<sumx<<' '<<sumy;
                //cout<<sum12[i].first<<' '<<sum12[i].second<<' '<<sum34[j].first<<' '<<sum34[j].second;
                //cout<<firstpart.first.first<<' '<<firstpart.first.second<<' '<<firstpart.second.first<<' '<<firstpart.second.second<<' '<<secondpart.first.first<<' '<<secondpart.first.second<<' '<<secondpart.second.first<<' '<<secondpart.second.second;
                return 0;
            }

        }
    }

	return 0;
}
