#include <bits/stdc++.h>

using namespace std;

typedef pair<long long,long long> star;

long long dist(long long x1,long long y1,long long x2,long long y2) {
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

long long dist(star a,star b) {
    return dist(a.first,a.second,b.first,b.second);
}

int main() {
    ifstream fs("fb01.txt");
    ofstream ofs("fb01out.txt");
    int t;fs>>t;
    for (int _t=1;_t<=t;_t++) {
        int n;fs>>n;
        vector< star > data(n);
        for (int i = 0;i<n;i++) {
            //data[i].first = 0;
            //data[i].second = i;
            fs>>data[i].first>>data[i].second;
        }
        //sort(data.begin(),data.end(),sortstar);
        long long result = 0;
        for (int i = 0;i<n;i++) {
            map<long long,long long> dcount;
            set<long long> dcountkey;
            for (int j = 0;j<n;j++) {
                if (i==j) continue;
                long long d = dist(data[i],data[j]);
                dcount[d]++;
                dcountkey.insert(d);
            }
            for (set<long long>::iterator j = dcountkey.begin();j!=dcountkey.end();j++) {
                //cout << i << " " << *j << " " << dcount[*j] << "\n";
                result += dcount[*j]*(dcount[*j]-1);
            }
        }



        ofs << "Case #" << _t << ": " << result/2 << "\n";
    }

    return 0;
}
