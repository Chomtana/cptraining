/*
Merge sort -> sort <
By Chomtana
*/

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


void mergesort(vector<int> &v,int start,int end) {
    if (start<end) {
        int mid = (start+end)/2;
        mergesort(v,start,mid);
        mergesort(v,mid+1,end);

        //merge array

        //wi te jum kea two pointer l,r lai pai jong tung end

        int l = start;
        int r = mid+1;

        vector<int> temp;

        //cout<<start<<' '<<' '<<mid<<' '<<end<<endl;
        while (l!=mid+1 || r!=end+1) {
            //cout<<l<<' '<<r<<endl;

            if (l == mid+1) {
                temp.push_back(v[r]);
                r++;
                continue; //important make it mai tum sum
            }
            if (r == end+1) {
                temp.push_back(v[l]);
                l++;
                continue; //important make it mai tum sum
            }
            if (v[l] < v[r]) { //por mun overflow tar lao mai nae jai wa mun mai run kern mun ja tum sum dai pork tua te overflow mun kor me kar here rai mai ru yu (run kern 1 kung mai nae jai pork ta lao mua condition leaw run kern dai)
                temp.push_back(v[l]);
                l++;
            } else {
                temp.push_back(v[r]);
                r++;
            }
        }

        for(int i = 0,j=start;i<temp.size();i++,j++) {
            v[j] = temp[i];
        }
    }

}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
	vector<int> data(n); for1(i,0,n) cin>>data[i];

    mergesort(data,0,n-1);

    for1(i,0,n) cout<<data[i]<<' ';

	return 0;
}
