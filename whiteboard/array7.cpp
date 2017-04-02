#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n,full; cin>>n>>full;
	double data[n];
	for1(i,0,n) cin>>data[i];
    double sum = 0;
    for1(i,0,n) {
        sum += data[i];
    }

    double xbar = sum/double(n);

    printf("Average score : %.2f\n",xbar);

    double sdsum = 0;
    for1(i,0,n) {
        sdsum += (data[i]-xbar)*(data[i]-xbar);
    }
    double sd = sqrt(sdsum/n);

    printf("SD score : %.2f\n",sd);

    int countless = 0;
    int countmore = 0;
    int countfull = 0;
    int currmin = 1E9;
    int currmax = 0;

    for1(i,0,n) {
        if (data[i]<xbar) countless++; else countmore++;
        if (data[i]==full) countfull++;
        currmin = min(currmin,int(data[i]));
        currmax = max(currmax,int(data[i]));
    }

    printf("< average count : %d\n",countless);
    printf(">= average count : %d\n",countmore);
    printf("Full score count : %d\n",countfull);
    printf("Max score : %d\n",currmax);
    printf("Min score : %d\n",currmin);



	return 0;
}
