#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;

ll res = 0;

void mergesort(vector<ll> &v,int start,int end) {
    if (start<end) {
        ll mid = (start+end)/2;
        mergesort(v,start,mid);
        mergesort(v,mid+1,end);

        //in this step we will always have 2 sorted array v[start:mid] , v[mid+1:end] , old index(start:mid) < old index(mid+1:end)
        int l = start;
        int r = mid+1;
        vector<ll> temp;

        vector<ll> qs(mid-start+1,0);

        qs[qs.size()-1] = v[mid];



        for1(i,1,qs.size()) {
            qs[qs.size()-1-i] = qs[qs.size()-i]+v[mid-i];
        }

        while (l!=mid+1 && r!=end+1) {
            if (v[l]<=v[r]) {
                temp.push_back(v[l]);
                l++;
            } else {
                temp.push_back(v[r]);
                res += qs[l-start];
                res += v[r]*(mid+1-l);
                r++;
            }
        }

        while (l!=mid+1) {
            temp.push_back(v[l]);
            l++;
        }

        while (r!=end+1) {
            temp.push_back(v[r]);
            r++;
        }

        for1(i,0,temp.size()) {
            v[start+i] = temp[i];
        }
    }
}

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
    int n; scanf("%d",&n);
    vector<pii> data(n); for1(i,0,n) cin>>data[i].first>>data[i].second;
    sort(all(data),[](pii a,pii b) {
        return a.second < b.second;
    });

    vector<ll> a(n);

    for1(i,0,n) a[i] = data[i].first;

    mergesort(a,0,n-1);

    //for1(i,0,n) cout<<a[i]<<' ';

    cout<<res;


	return 0;
}
