#include <bits/stdc++.h>
#include "traffic.h"

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<pii,pii> piiii;

vector<piiii> ans;
vector<piii> ab;
int n,k;

int check(int s,int e,int pos,int type) {
    int x = (type==0?traffic_query(pos,s,pos,e):traffic_query(s,pos,e,pos));
    return x-(e-s);
}

void dobomb(int pos,int type,int size,int s,int e) {
    //cout<<pos.first<<' '<<pos.second<<endl;
    //int s = 1,e=n;
    while (s<e) {
        if (e-s==1) {
            if (type==0) {
                ans.push_back({{pos,s},{pos,e}});
            } else {
                ans.push_back({{s,pos},{e,pos}});
            }
            return;
        }
        
        //cerr<<s<<' '<<e<<endl;
        
        int mid = (s+e)/2;
        int x = check(s,mid,pos,type);
        //cerr<<s<<' '<<mid<<' '<<pos<<endl;
        if (x==0) {
            s = mid;
        } else if (x==size) {
            e = mid;
        } else {
            //cerr<<"aaa"<<endl;
            dobomb(pos,type,1,s,mid);
            dobomb(pos,type,1,mid,e);
            return;
            /*if (k==1) {
                if (type==0) {
                    ans.push_back({{pos,mid-x},{pos,mid+size-x}});
                } else {
                    ans.push_back({{mid-x,pos},{mid+size-x,pos}});
                }
                return;
            } else {
                
            }*/
        }
    }
}

void specialbomb(pii pos) {
    
}

int main() {
    traffic_init(&n,&k);
    bool special = false;
    
    for1(i,1,n+1) {
        int x = traffic_query(i,1,i,n);
        //cerr<<"TQ "<<i<<' '<<x<<endl;
        if (x>=n) {
            if (x-(n-1)==n-1) {
                ans.push_back({{i,1},{i,n}});
            } else {
                //dobomb(i,0,x-(n-1));
                ab.push_back({{i,0},x-(n-1)});
            }
        }
        
        x = traffic_query(1,i,n,i);
        if (x>=n) {
            if (x-(n-1)==n-1) {
                ans.push_back({{1,i},{1,n}});
            } else {
                //dobomb(i,1,x-(n-1));
                ab.push_back({{i,1},x-(n-1)});
            }
        }
    }
    
    if (!special) {
        if (ab.size()>=1) {
            dobomb(ab[0].first.first,ab[0].first.second,ab[0].second,1,n);
            if (ab.size()==2) {
                dobomb(ab[1].first.first,ab[1].first.second,ab[1].second,1,n);
            }
        }
    } else {
        //specialbomb(ab[0]);
    }
    
    //printf("%d %d %d %d\n",ans[0].first.first,ans[0].first.second,ans[0].second.first,ans[0].second.second);
    if (ans.size()==1) {
        traffic_report(ans[0].first.first,ans[0].first.second,ans[0].second.first,ans[0].second.second,0,0,0,0);
    } else if (ans.size()==2) {
        traffic_report(ans[0].first.first,ans[0].first.second,ans[0].second.first,ans[0].second.second,ans[1].first.first,ans[1].first.second,ans[1].second.first,ans[1].second.second);
    }
    
    /*cout<<traffic_query(1,1,1,5)<<endl;
    cout<<traffic_query(2,1,2,5)<<endl;
    cout<<traffic_query(3,1,3,5)<<endl;
    cout<<traffic_query(4,1,4,5)<<endl;
    cout<<traffic_query(5,1,5,5)<<endl;
    cout<<"----------------------"<<endl;*/
    
    return 0;
}