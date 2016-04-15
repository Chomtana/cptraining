#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;

using namespace std;

bool datasort(pair<char,long long> a,pair<char,long long> b) {
    if (a.second > b.second) return true;
    if (a.second < b.second) return false;
    
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
}

int main() {
    cout<<fixed;
    ios::sync_with_stdio(false);
    
    vector< pair<char,long long> > data(7);
    for1(i,0,7) {
        data[i].first = i+'A';
    }
    int remaining = 7;
    string s; cin>>s;
    while (s!="!") {
        
        for1(i,0,s.size()) {
            if (data[s[i]-'A'].second >= 0) {
                data[s[i]-'A'].second++;
            }
            //cout<<s[i]<<' '<<s[i]-'A'<<endl;
        }
        
        long long currmin = 9999999;
        int res = -1;
        //bool ok = true;
        for1(i,0,7) {
            if (data[i].second!=-1 && data[i].second<currmin) {
                currmin = data[i].second;
                res = i;
            } else if (data[i].second!=-1 && data[i].second==currmin) {
                res = -1;
            }
        }
        if (res!=-1 && remaining>1) {
            data[res].second=-1;
            remaining--;
        }
        
        cin>>s;
    }
    
        
    sort(data.begin(),data.end(),datasort);
    
    int count = 0;
    ostringstream out; //print count then print out
    for1(i,0,data.size()) {
        if (data[i].second > 0) {
            out<<data[i].first<<' '<<data[i].second<<endl;
            count++;
        }
    }
    cout<<count<<endl<<out.str();
    
    return 0;
}