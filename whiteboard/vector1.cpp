#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define until(x) while(!(x))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	srand(time(0));
	int n = rand()%(20-10+1)+10;
	vector<int> leven;
	vector<int> lodd;
	cout<<"--- Random Numbers ["<<n<<"] ---"<<endl;
    for1(i,0,n) {
        int ins = rand()%(100-1+1)+1;
        if (ins%2==0) {
            leven.push_back(ins);
        } else {
            lodd.push_back(ins);
        }
        cout<<ins<<' ';
    }
    cout<<endl;
    cout<<"---- Even Linked List ["<<leven.size()<<"] ---"<<endl;
    for1(i,0,leven.size()) cout<<leven[i]<<' ';
    cout<<endl;
    cout<<"---- Odd Linked List ["<<lodd.size()<<"] ---"<<endl;
    for1(i,0,lodd.size()) cout<<lodd[i]<<' ';
    cout<<endl;

    until(leven.empty() || lodd.empty()) {
        if (leven[leven.size()-1] > lodd[lodd.size()-1]) {
            leven.pop_back();
        } else {
            lodd.pop_back();
        }
    }

    if (leven.empty()) {
        cout<<"===> Even is the winner!";
    } else {
        cout<<"===> Odd is the winner!";
    }


	return 0;
}
