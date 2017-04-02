#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n[9];

int res = 0;

void process(int target,int &want) {
    for1(i,target,9) {
        if (n[i]*(i/target)<=want) {
            int dec = n[i]*(i/target);
            want -= dec;
            n[i%target] += n[i];
            n[i] = 0;

        } else {
            int dec = (want-1)/(i/target)+1;
            if (want==0) dec=0;

            if (want%(i/target) == 0) {
                n[i%target] += dec;
            } else {
                n[i%target] += dec-1;
                n[i-target*(want%(i/target))] += 1;
            }
            n[i] -= dec;
            want = 0;
        }
    }
    if (want!=0) {
        res += ceil(double(want)/(8/double(target)));
        n[8] += ceil(double(want)/(8/double(target)));
        cout<<target<<' '<<n[8]<<' '<<want<<endl;
        for1(i,1,9) {
            cout<<n[i]<<' ';
        }
        cout<<endl;
        process(target,want);
        //cout<<target<<' '<<n[8]<<' '<<want<<endl;
        for1(i,1,9) {
            cout<<n[i]<<' ';
        }
        cout<<endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; scanf("%d",&t);



    while (t--) {
        int a,b,c,d,e; scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        res += a;

        //b
        process(6,b);
        process(4,c);
        process(2,d);
        process(1,e);

    }

    cout<<res;
	return 0;
}
