#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int sum[105][105];
//int data[105][105];
string data[105];

int query(int sr,int sc,int er,int ec) {
    return sum[er][ec]-sum[sr-1][ec]-sum[er][sc-1]+sum[sr-1][sc-1];
}

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    int t; cin>>t;
    for1(_,1,t+1) {
        int r,c,h,v; scanf("%d %d %d %d",&r,&c,&h,&v);
        printf("Case #%d: ",_);
        memset(sum,0,sizeof(sum));
        for1(i,0,r) {
            cin>>data[i];
        }
        
        for1(i,1,r+1) {
            for1(j,1,c+1) {
                if (i==0 && j==0) {
                    sum[i][j] = (data[i-1][j-1]=='@'?1:0);
                } else {
                    if (i==0) {
                        sum[i][j] = sum[i][j-1]+(data[i-1][j-1]=='@'?1:0);
                    } else if (j==0) {
                        sum[i][j] = sum[i-1][j]+(data[i-1][j-1]=='@'?1:0);
                    } else {
                        sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(data[i-1][j-1]=='@'?1:0);
                    }
                }
            }
        }
        
        /*for1(i,0,r+1) {
            for1(j,0,c+1) {
                printf("%d ",sum[i][j]);
            }
            printf("\n");
        }*/
        
        
        
        //cerr<<query(2,4,3,6)<<endl;
        
        for1(i,1,r) {
            for1(j,1,c) {
                int x1 = query(1,1,i,j);
                int x2 = query(1,j+1,i,c);
                int x3 = query(i+1,1,r,j);
                int x4 = query(i+1,j+1,r,c);
                if (x1==x2 && x2==x3 && x3==x4) {
                    printf("POSSIBLE\n");
                    goto nextcase;
                }
                
                /*int base = sum[i][j];
                int sr = i+1;
                int sc = j+1;
                bool fail = false;
                vector<int> V(2,j);
                vector<int> H(2,i);
                V[0] = 0; H[0] = 0;
                
                for1(k,j+1,c+1) {
                    //printf("(%d,%d,%d) V : %d %d %d %d : %d\n",i,j,base,0,V.back()+1,i,k,query(0,V.back()+1,i,k));
                    if (query(0,V.back()+1,i,k)>base) {
                        fail = true;
                        break;
                    }
                    if (query(0,V.back()+1,i,k)==base) {
                        V.push_back(k);
                    }
                }
                //printf("(%d,%d,%d) V => %d => %d %d\n",i,j,base,fail,V.size(),V.back());
                if (V.size()!=v+2 || V.back()!=c) continue;
                if (fail) continue;
                
                for1(k,i+1,r+1) {
                    //printf("(%d,%d,%d) H : %d %d %d %d : %d\n",i,j,base,H.back()+1,0,k,j,query(H.back()+1,0,k,j));
                    if (query(H.back()+1,0,k,j)>base) {
                        fail = true;
                        break;
                    }
                    if (query(H.back()+1,0,k,j)==base) {
                        H.push_back(k);
                    }
                }
                if (H.size()!=h+2 || H.back()!=r) continue;
                if (fail) continue;
                
                
                bool check = true;
                for1(x,1,H.size()) {
                    for1(y,1,V.size()) {
                        if (query(H[x-1]+1,V[y-1]+1,H[x],V[y])!=base) {
                            check = false;
                            break;
                        }
                    }
                }
                
                if (check) {
                    printf("POSSIBLE\n");
                    goto nextcase;
                }*/
                
                /*for1(_x,0,H.size()) cerr<<H[_x]<<' '; cerr<<endl;
                for1(_x,0,V.size()) cerr<<V[_x]<<' '; cerr<<endl;
                cerr<<endl;*/
            }
        }
        
        printf("IMPOSSIBLE\n");
        
        nextcase:
        continue;
    }
    return 0;
}
