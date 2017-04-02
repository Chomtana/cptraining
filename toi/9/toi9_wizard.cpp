#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

class Hasher {
    public:
    size_t operator () (const pii &data) const {
        return data.first;
    }
};

void print(pair<pii,pii> &p) {
    printf("%d %d\n%d %d\n",p.first.first,p.first.second,p.second.first,p.second.second);
    //cout<<p.first.first<<' '<<p.first.second<<' '<<p.second.first<<' '<<p.second.second<<endl;
}

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
    ll xt,yt; scanf("%lld %lld",&xt,&yt); //cin>>xt>>yt;
    int n; scanf("%d",&n);
    //cout<<xt<<' '<<yt<<' '<<n<<endl;
    pii data1[n]; for1(i,0,n) /*cin>>data1[i].first>>data1[i].second;*/scanf(" %d %d",&data1[i].first,&data1[i].second);
    pii data3[n];
    //pii data2[n]; for1(i,0,n) /*cin>>data2[i].first>>data2[i].second;*/scanf(" %lld %lld",&data2[i].first,&data2[i].second);

    //sort(data3,data3+n);
    //sort(data4,data4+n);

    //for1(i,0,n) scanf("")

    //vector<pii> sum12;
    unordered_map<pii,pair<pii,pii>,Hasher> res12(2e7);

    for1(i,0,n) {
        int data2first,data2second; scanf(" %d %d",&data2first,&data2second);
        for1(j,0,n) {
            int sumx = data1[j].first+data2first;
            int sumy = data1[j].second+data2second;
            //sum12.push_back(mp(sumx,sumy));
            res12[mp(xt-sumx,yt-sumy)] = mp(data1[j],mp(data2first,data2second));
            //pair<pii,pii> dbg = mp(mp(data1[i].first,data1[i].second),mp(data2[j].first,data2[j].second));
            //print(dbg);
            //cout<<data1[i].first<<' '<<data1[i].second<<' '<<data2[j].first<<' '<<data2[j].second<<endl;
        }
    }

    for1(i,0,n) /*cin>>data3[i].first>>data3[i].second;*/scanf(" %d %d",&data3[i].first,&data3[i].second);
    //pii data4[n]; for1(i,0,n) /*cin>>data4[i].first>>data4[i].second;*/scanf(" %lld %lld",&data4[i].first,&data4[i].second);

    for1(i,0,n) {
        int data4first,data4second; scanf(" %d %d",&data4first,&data4second);
        for1(j,0,n) { //do 3,4 -> find wa me 2,3 pow (lao ja ru dai wa tong use 2+3 pen a rai , lao cache 2+3 wai leaw)
            int sumx = data3[j].first+data4first;
            int sumy = data3[j].second+data4second;
            //int needx = xt-sumx;
            //int needy = yt-sumy;
            //cout<<data3[i].first<<' '<<data4[j].first<<' '<<sumx<<' '<<sumy<<' '<<needx<<' '<<needy<<endl;
            if (res12.count(mp(sumx,sumy))==1) {
                pair<pii,pii> firstpart = res12[mp(sumx,sumy)];
                print(firstpart);
                printf("%d %d\n%d %d",data3[j].first,data3[j].second,data4first,data4second);
                return 0;
            }
        }
    }


	return 0;
}

/*
-2 2
2
1 2 -2 10
-6 -6 -1 3
-1 -2 -6 -5
5 -4 7 0
*/
