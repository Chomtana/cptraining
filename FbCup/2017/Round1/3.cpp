#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;

//dp because path 1 tum  tua te 8 mai la path 1000 mun kor  tong tum tua te 8 mai -> overlap found

vi dataS;
vi dataE;
vector<vector<pii>> E;
vector<vi> sp; //shortest path (all-pair)
ll n,m,q;
bool noans = false;

map< int, map< ll, map<int,ll> > > dp;

ll dodp(int curr,ll start,int rub) {
    if (curr>=q) {
        return 0;
    }
    if (noans) return -1;

    if (dp[curr][start].count(rub) != 0) {
        return dp[curr][start][rub];
    }

    ll startcost = sp[start][dataS[curr]];
    ll movecost = sp[dataS[curr]][dataE[curr]];
    vi nextcost;
    if (startcost >= 1E16) {
        noans = true;
    }
    if (rub!=-1) {
        //song 1
        //pai (startcost)
        //case song kon 1 -> yung rub kon 2
        ll next1 = sp[dataS[curr]][dataE[rub]] + dodp(curr+1,dataE[rub],curr);
        //case song kon 2 -> yung tub kon 1
        //ll next2 = sp[dataS[curr]][dataE[curr]] + dodp(curr+1,dataE[curr],rub);
        //case song tung 2 kon -> 1->2 / 2->1 -> mai rub leaw
        ll next12 = sp[dataS[curr]][dataE[rub]] + sp[dataE[rub]][dataE[curr]] + dodp(curr+1,dataE[curr],-1);
        //ll next21 = sp[dataS[curr]][dataE[curr]] + sp[dataE[curr]][dataE[rub]] + dodp(curr+1,dataE[rub],-1);
        if (curr+1<q) nextcost.push_back(next1);
        //nextcost.push_back(next2);
        nextcost.push_back(next12);
        //nextcost.push_back(next21);
    } else {
        //mai rub
        //tum tor doi start te end kong  tua ne
        ll nextmai = movecost+dodp(curr+1,dataE[curr],-1);
        //rub
        ll nextrub = dodp(curr+1,dataS[curr],curr);

        nextcost.push_back(nextmai);
        if (curr+1<q) nextcost.push_back(nextrub);
    }


    dp[curr][start][rub] = startcost+(*min_element(all(nextcost)));

    return dp[curr][start][rub];
}

ll main2() {
    cin>>n>>m>>q;
    E.resize(n+1);
    sp.resize(n+1,vi(n+1,1E16));
    dataS.resize(q);
    dataE.resize(q);
    bool found[n+1];
    fill(found,found+n+1,false);
    for1(i,0,m) {
        ll s,e,g; cin>>s>>e>>g;
        found[s] = true;
        found[e] = true;
        //me multiple edge mai use la kor yung sung  pun ha eek
        //E[s].push_back(mp(e,g));
        //E[e].push_back(mp(s,g));
        //make sp start with direct edge weight
        sp[s][e] = min(sp[s][e],g);
        sp[e][s] = min(sp[e][s],g);
        sp[s][s] = 0;
        sp[e][e] = 0;
    }

    for1(i,0,q) {
        ll s,e; cin>>s>>e;
        if (!found[s] || !found[e]) {
            noans = true;
        }
        dataS[i] = s;
        dataE[i] = e;
    }

    for1(k,1,n+1) {
        for1(i,1,n+1) {
            for1(j,1,n+1) {
                sp[i][j] = min(sp[i][j],sp[i][k]+sp[k][j]);
            }
        }
    }

    ll res = (noans?-1:dodp(0,1,-1));


    E.clear();
    sp.clear();
    dataS.clear();
    dataE.clear();
    dp.clear();
    noans = false;
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    //keep sum bab mai long nai array mai
    //keep sum bab rub long nai array rub doi ta rub 4,5 sai long nai rub[5]
    //if mai mai sum < rub  then choose mai mai else choose rub
	int t; cin>>t;
	for1(_t,1,t+1) {
	    ll res = main2();
        cout<<"Case #"<<_t<<": "<<res<<endl;
        cerr<<"Case #"<<_t<<": "<<res<<endl;
	}

	return 0;
}
