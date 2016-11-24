#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;
typedef priority_queue<ll,vector<ll>,greater<ll>> minpq_;
typedef priority_queue<ll> maxpq_;

int main() {
    ios::sync_with_stdio(false);
    ll n;
    maxpq_ part1;
    minpq_ part2;
    while (cin>>n) {
        if (part1.size()==0) {
            part1.push(n);
            cout<<n<<endl;
            continue;
        } else if (part2.size()==0) {
            part2.push(n);
            cout<<(part1.top()+n)/2<<endl;
            if (part1.top()>part2.top()) {
                ll p1 = part1.top();
                ll p2 = part2.top();
                part1.pop();
                part2.pop();
                part1.push(p2);
                part2.push(p1);
            }
            continue;
        }

        //cerr<<"aaa "<<n<<' '<<part1.top()<<endl;
        if (n<=part1.top()) {
            part1.push(n);
        } else {
            part2.push(n);
        }

        if (part2.size()>part1.size()) {

            part1.push(part2.top());
            part2.pop();
        } else if (part1.size()>part2.size()+1) {
            part2.push(part1.top());
            part1.pop();
        }

        //cerr<<part1.size()<<' '<<part2.size()<<endl;
        if (part2.size()==part1.size()) {
            cout<<(part1.top()+part2.top())/2<<endl;
        } else {
            cout<<part1.top()<<endl;
        }
    }


    return 0;
}
