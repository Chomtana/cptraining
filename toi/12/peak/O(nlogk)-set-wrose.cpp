/*
A(30,000,000) if test case isn't incredible (Use sense : 5,000,000 element wrost must 2,500,000 element -> O(80,000,000) (high low sa rub kun) but if random it is hard to get this test case )

use set

use three adjacency element process at construction algorithm
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

//int data[5000005];
set<int,greater<int>> peak;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,k; cin>>n>>k;

    //peak.reserve(5000005); //make size large enough -> push back no amotized -> mai tong sea we la eek O(n)

    //data[0] = 0;
    //data[n+1] = 0;
    int before = 0; //data[i-1]
    int curr = 0; //data[i]
    int after = 0; //data[i+1]
    //if curr not right -> mun ja tam 1 kung (use sci to simulate)
    for1(i,1,n+1) {
        scanf("%d",&after); //always input right

        //case tam (0,0,x) -> always don't do -> correct
        if (curr>before && curr>after) {
            peak.insert(curr);
        }

        before = curr;
        curr = after;
    }
    //when loop finish if curr isn't right of three element then it will require extra step (use sci to simulate)
    after = 0;
    if (curr>before && curr>after) {
        peak.insert(curr);
    }



    /*for1(i,1,n+1) {
        if (data[i]>data[i-1] && data[i]>data[i+1]) {
            peak.push_back(data[i]);
        }
    }*/

    //sort(all(peak),greater<int>());

    //peak.resize(unique(all(peak))-peak.begin());

    if (peak.size()==0) {
        cout<<-1; return 0;
    }

    if(peak.size()<k) {
        for(auto it = peak.rbegin();it!=peak.rend();it++) {
            printf("%d\n",*it);
        }
    } else {
        auto it = peak.begin();
        while (k--) {
            printf("%d\n",*it);
            it++;
        }
    }
	return 0;
}
