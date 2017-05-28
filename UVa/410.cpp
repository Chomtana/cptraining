#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int c,s;
    int _ = 1;
    while (cin>>c>>s) {
        int msum = 0;
        deque<int> data(s); for1(i,0,s) {
            cin>>data[i];
            msum += data[i];
        }

        double ave = (double)(msum)/(double)(c);
        //cout<<ave<<endl;

        while (data.size()<2*c) {
            data.push_back(0);
        }

        sort(all(data));

        printf("Set #%d\n", _++);

        double imsum = 0;

        //vector<pii> res(c);
        for1(i,0,c) {
            double cm = 0;

            printf("%2d:", i);
            if (data[0]!=0) {
                printf(" %d", data[0]);
                cm += data[0];
            }
            if (data.back() != 0) {
                printf(" %d", data.back());
                cm+= data.back();
            }
            printf("\n");

            imsum += abs(cm-ave);
            //res[i].first = data[0];
            //res[i].second = data.back();
            data.pop_front();
            data.pop_back();
        }

        printf("IMBALANCE = %.5lf\n\n", imsum);
    }
	return 0;
}
