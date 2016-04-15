#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> star;

bool sortstar(star a,star b) {
    if (a.first<b.first) return true;
    if (a.first>b.first) return false;

    if (a.second<b.second) return true;
    if (a.second>b.second) return false;

    return true;
}

double dist(double x1,double y1,double x2,double y2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

double dist(star a,star b) {
    return dist(a.first,a.second,b.first,b.second);
}

int main() {
    int t;cin>>t;
    for (int _t=1;_t<=t;_t++) {
        int n;cin>>n;
        vector< star > data(n);
        for (int i = 0;i<n;i++) {
            //data[i].first = 0;
            //data[i].second = i;
            cin>>data[i].first>>data[i].second;
        }
        //sort(data.begin(),data.end(),sortstar);
        int result = 0;
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<n;j++) {
                if (i==j) continue;
                double dist1 = dist(data[i],data[j]);
                for (int k = 0;k<n;k++) {
                    if (i==k || j==k) continue;
                    double dist2 = dist(data[i],data[k]);
                    if (dist1 == dist2) {
                        //cout <<i<<" "<<j<<" "<<k<<" "<<dist1<<" "<<dist2<<"\n";

                        result++;
                    }
                }
            }
        }

        cout << "Case #" << _t << ": " << result/2 << "\n";
    }

    return 0;
}
