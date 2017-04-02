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
        return hash<ll>()(data.first+data.second);
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

    //sort(data3,data3+n);
    //sort(data4,data4+n);

    //for1(i,0,n) scanf("")

    //vector<pii> sum12;
    unordered_map<pii,pair<pii,pii>,Hasher> res12;



    for1(i,0,n) {
        for1(j,0,n) {
            int sumx = data1[i].first+data2[j].first;
            int sumy = data1[i].second+data2[j].second;
            //sum12.push_back(mp(sumx,sumy));
            res12[mp(sumx,sumy)] = mp(data1[i],data2[j]);
            //pair<pii,pii> dbg = mp(mp(data1[i].first,data1[i].second),mp(data2[j].first,data2[j].second));
            //print(dbg);
            //cout<<data1[i].first<<' '<<data1[i].second<<' '<<data2[j].first<<' '<<data2[j].second<<endl;
        }
    }

    for1(i,0,n) {
        for1(j,0,n) { //do 3,4 -> find wa me 2,3 pow (lao ja ru dai wa tong use 2+3 pen a rai , lao cache 2+3 wai leaw)
            int sumx = data3[i].first+data4[j].first;
            int sumy = data3[i].second+data4[j].second;
            int needx = xt-sumx;
            int needy = yt-sumy;
            //cout<<data3[i].first<<' '<<data4[j].first<<' '<<sumx<<' '<<sumy<<' '<<needx<<' '<<needy<<endl;
            /*if (res12.count(mp(needx,needy))>0) {
                pair<pii,pii> firstpart = res12[mp(needx,needy)];
                print(firstpart);
                printf("%lld %lld\n%lld %lld",data3[i].first,data3[i].second,data4[j].first,data4[j].second);
                return 0;
            }*/
        }
    }


	return 0;
}
