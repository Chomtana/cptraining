#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<int> ready;
vector<int> seat;
int maxseat;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n,k; cin>>n>>k;
    ready.resize(k,0);
    seat.resize(k,0);

    for1(i,0,k) {
        cin>>seat[i];
    }
    maxseat = *max_element(all(seat));
    for1(i,0,n) {
        int s,d; cin>>s>>d;
        if (s>maxseat) {
            cout<<"sorry"<<endl;
        } else {
            //find max seat that <= tua derm
            //min dif that >=
            int currmin1 = 1E9;
            int mini1 = -1;
            for1(j,0,k) {
                if (seat[j] >= s) {
                    int dif = seat[j]-s;
                    if (dif < currmin1) {
                        currmin1 = dif;
                        mini1 = j;
                    }
                }
            }

            //find min use that == currmin1
            int currmin2 = 1E9;
            int mini2 = -1;
            for1(j,0,k) {
                if (seat[j] == seat[mini1]) {
                    if (ready[j] < currmin2) {
                        currmin2 = ready[j];
                        mini2 = j;
                    }
                }
            }

            ready[mini2] += d;
            cout<<mini2+1<<endl;

        }
    }

	return 0;
}
