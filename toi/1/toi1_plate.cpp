#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
    int nc,ns; cin>>nc>>ns;
    deque<int> subq[nc]; //subq[class] = <class> queue
    for1(i,0,nc) {
        subq[i]=deque<int>();
    }
    deque<int> q; //queue = {...class...}
    int stoc[1001]; //convert student to class
    for1(i,0,ns) {
        int c,s; cin>>c>>s;
        c--;
        stoc[s]=c;
    }
    char command;
    while (cin>>command , command != 'X') {
        switch (command) {
        case 'E': {
            int s; cin>>s;
            int c = stoc[s];
            //cout<<s;
            if (subq[c].size()==0) {
                q.push_back(c);
            }
            subq[c].push_back(s);
        } break;
        case 'D': {
            if (!q.empty()) {
                int c = q[0];
                int s = subq[c][0];
                cout<<s<<endl;
                subq[c].pop_front();
                if (subq[c].empty()) {
                    q.pop_front();
                }
            } else {
                cout<<"empty"<<endl;
            }
        }
        }
    }
    cout<<0;

    return 0;
}
