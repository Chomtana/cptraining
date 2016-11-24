#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef map<char,int> mc;

char itotype(int i) {
    switch (i) {
        case 0: return 'S';
        case 1: return 'H';
        case 2: return 'D';
        case 3: return 'C';
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

    while (true) {
        map<char,mc> c1; //c[type][val]
        mc c2; //c2[val]
        mc c3; //c3[type]
        map<char,bool> stopped;
        for1(i,0,13) {
            char val,type; if(!(cin>>val>>type)) return 0;
            c1[type][val]++;
            c2[val]++;
            c3[type]++;
        }
        ll p = 0;
        ll pig = 0; //p ignore 5,6,7
        p+=c2['A']*4;
        p+=c2['K']*3;
        p+=c2['Q']*2;
        p+=c2['J']*1;

        pig = p;

        for1(i,0,4) {
            char type = itotype(i);
            if (c1[type]['K']>0&&c3[type]==c1[type]['K']) {
                p--;
                pig--;
            }
            if (c1[type]['Q']>0&&(c3[type]==c1[type]['Q']||c3[type]==c1[type]['Q']+1)) {
                p--;
                pig--;
            }
            if (c1[type]['J']>0&&(c3[type]==c1[type]['J']||c3[type]==c1[type]['J']+1||c3[type]==c1[type]['J']+2)) {
                p--;
                pig--;
            }
            if (c3[type]==2) p++;
            if (c3[type]==1) p+=2;
            if (c3[type]==0) p+=2;
            if ((c1[type]['A']==1) || (c1[type]['K']==1&&c3[type]>1) || (c1[type]['Q']==1&&c3[type]>2)) stopped[type] = true;
        }

        if (p < 14) { cout<<"PASS"<<endl; continue; }
        else {
            if (pig>=16 && stopped['S'] && stopped['H'] && stopped['D'] && stopped['C']) {
                cout<<"BID NO-TRUMP"<<endl; continue;
            } else {
                int currmax = 0;
                char maxtype;
                for1(i,0,4) {
                    char type = itotype(i);
                    if (c3[type]>currmax) {
                        currmax = c3[type];
                        maxtype = type;
                    }
                }
                cout<<"BID "<<maxtype<<endl; continue;
            }
        }



    }
	return 0;
}
