#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
vector<pii> data;

int main() {
    cin>>n;
    for1(i,0,n) {
        int p,h; scanf("%d%d",&p,&h);
        data.emplace_back(p,h);
    }
    
    for1(i,0,n) {
        int p = data[i].first;
        int h = data[i].second;
        int count = 0;
        for1(j,0,i) {
            int hj = data[j].second-abs(data[i].first-data[j].first);
            if (hj>=h) {
                count++;
                continue;
            }
            
            /*if (data[j].second>=h+abs(data[i].first-data[j].first)) {
                count++;
            }*/
            
            /*int hi = data[i].second-abs(data[i].first-data[j].first);
            if (hi>=data[j].second) {
                count++;
            }*/
        }
        printf("%d\n",count);
    }
    return 0;
}