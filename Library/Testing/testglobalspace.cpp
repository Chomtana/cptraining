#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int global[100];

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int local[100];
	cout<<"Global space fill 0 as start val : "<<endl;
	for1(i,0,100) cout<<global[i]<<' ';
	cout<<endl<<endl;
	cout<<"Fuck you local space don't fill ... !!!pointer mai fill NULL hai!!! : "<<endl;
    for1(i,0,100) cout<<local[i]<<' ';
	return 0;
}
