#include <bits/stdc++.h>

using namespace std;

struct postype {
    int s,i; //data[s][i]
};

int main() {
    ios::sync_with_stdio(false);
    int n; cin>>n;
    deque<int> data[n];
    postype pos[n]; //index of <input> in array data (data[.s][.i] = <input>)
    for(int i = 0;i<n;i++) {
        data[i].push_back(i);
        pos[i].s = i;
        pos[i].i = 0;
    }
    string com1; cin>>com1;
    while (com1!="quit") {
        int a,b;
        string com2;
        cin>>a>>com2>>b;
        if (com1 == "move") {
            if (com2=="onto") {
                if (pos[a].s == pos[b].s) goto next;
                
                //return a,b
                while (data[pos[a].s][data[pos[a].s].size()-1]!=a) {
                    int val = data[pos[a].s][data[pos[a].s].size()-1];
                    data[pos[a].s].pop_back();
                    data[val].push_front(val);
                    pos[val].s = val;
                    pos[val].i = 0;
                }
                while (data[pos[b].s][data[pos[b].s].size()-1]!=b) {
                    int val = data[pos[b].s][data[pos[b].s].size()-1];
                    data[pos[b].s].pop_back();
                    data[val].push_front(val);
                    pos[val].s = val;
                    pos[val].i = 0;
                }
                
                //move a (final element) to b
                data[pos[a].s].pop_back();
                data[pos[b].s].push_back(a);
                pos[a].s = pos[b].s;
                pos[a].i = data[pos[b].s].size()-1;
            } else { //over
                if (pos[a].s == pos[b].s) goto next;
            
                //return a
                while (data[pos[a].s][data[pos[a].s].size()-1]!=a) {
                    int val = data[pos[a].s][data[pos[a].s].size()-1];
                    data[pos[a].s].pop_back();
                    data[val].push_front(val);
                    pos[val].s = val;
                    pos[val].i = 0;
                }
                
                //move a (final element) to b
                data[pos[a].s].pop_back();
                data[pos[b].s].push_back(a);
                pos[a].s = pos[b].s;
                pos[a].i = data[pos[b].s].size()-1;
            }
        } else { //pile
            if (com2=="onto") {
                if (pos[a].s == pos[b].s) goto next;
                
                //return b
                while (data[pos[b].s][data[pos[b].s].size()-1]!=b) {
                    int val = data[pos[b].s][data[pos[b].s].size()-1];
                    data[pos[b].s].pop_back();
                    data[val].push_front(val);
                    pos[val].s = val;
                    pos[val].i = 0;
                }
                
                //move [final element,a] to b (push_back and keep order (!!not reverse!!))
                int newposa = 0;
                
                for (int i = pos[a].i;i<data[pos[a].s].size();i++) {
                    int val = data[pos[a].s][i];
                    data[pos[b].s].push_back(data[pos[a].s][i]);
                    if (i==pos[a].i) {
                        newposa = data[pos[b].s].size()-1;
                    } else {
                        pos[data[pos[a].s][i]].s = pos[b].s;
                        pos[data[pos[a].s][i]].i = data[pos[b].s].size()-1;
                    }
                }
                
                //remove duplicate element from a
                while (data[pos[a].s][data[pos[a].s].size()-1]!=a) {
                    data[pos[a].s].pop_back();
                }
                data[pos[a].s].pop_back();
                pos[a].s = pos[b].s;
                pos[a].i = newposa;
                
            } else { //over
                if (pos[a].s == pos[b].s) goto next;
            
                //no return
                
                //move [final element,a] to b (push_back and keep order (!!not reverse!!))
                int newposa = 0;
                
                for (int i = pos[a].i;i<data[pos[a].s].size();i++) {
                    int val = data[pos[a].s][i];
                    data[pos[b].s].push_back(data[pos[a].s][i]);
                    if (i==pos[a].i) {
                        newposa = data[pos[b].s].size()-1;
                    } else {
                        pos[data[pos[a].s][i]].s = pos[b].s;
                        pos[data[pos[a].s][i]].i = data[pos[b].s].size()-1;
                    }
                }
                
                //remove duplicate element from a
                while (data[pos[a].s][data[pos[a].s].size()-1]!=a) {
                    data[pos[a].s].pop_back();
                }
                data[pos[a].s].pop_back();
                pos[a].s = pos[b].s;
                pos[a].i = newposa;
            }
        }
        
        next:
        cin>>com1;
    }
    for (int i = 0;i<n;i++) {
        cout<<i<<':';
        for (int j = 0;j<data[i].size();j++) {
            cout<<' '<<data[i][j];
        }
        //if (data[i].size()==0) cout<<' ';
        cout<<endl;
    }
    return 0;
}