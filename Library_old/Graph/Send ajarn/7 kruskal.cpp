#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

class djnode {
public:
    int parent;
    int rank = 0;

    djnode() {

    }
};

class djset {
public:
    vector<djnode> dj;

    djset(int size) {
        dj.resize(size);
        for1(i,0,size) {
            dj[i].parent = i;
        }
    }

    int find(int a) {
        if (dj[a].parent==a) return a;
        dj[a].parent = find(dj[a].parent);
        return find(dj[a].parent);
    }

    void un(int a,int b) {
        a = find(a);
        b = find(b);
        if (dj[a].rank>dj[b].rank) {
            dj[b].parent = a;
            dj[a].rank++;
        } else {
            dj[a].parent = b;
            dj[b].rank++;
        }
    }


};

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int nv,ne; cin>>nv>>ne;
    vector<vector<pii>> E(nv+1);
    deque<pair<int,pii>> Earr;
    for1(i,0,ne) {
        int s,e,w; cin>>s>>e>>w;
        E[s].push_back(mp(e,w));
        E[e].push_back(mp(s,w));
        Earr.push_back(mp(w,mp(s,e)));
    }

    sort(all(Earr));

    djset dj(nv+1);

    vector<pii> selected;
    int sigmaw = 0;

    //cout<<"DBG"<<endl;
    while (selected.size()<nv-1) {
        pii mine = Earr[0].second;
        //cout<<mine.first<<' '<<mine.second<<' '<<dj.find(mine.first)<<' '<<dj.find(mine.second)<<endl;
        if (dj.find(mine.first) != dj.find(mine.second)) {
            selected.push_back(mine);
            sigmaw+=Earr[0].first;
            dj.un(mine.first,mine.second);
        }

        Earr.pop_front();
    }

    //sort(all(selected));

    cout<<"Sum of MST weight : "<<sigmaw<<endl;
    for1(i,0,selected.size()) {
        cout<<selected[i].first<<' '<<selected[i].second<<endl;
    }






    return 0;
}

/*
10 11
1 5 3
5 4 1
2 6 2
6 3 6
5 6 8
7 8 3
7 9 11
8 9 9
7 10 2
2 7 8
3 8 5
*/
