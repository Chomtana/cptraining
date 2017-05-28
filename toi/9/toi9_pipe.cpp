#include <bits/stdc++.h>

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

int data[301][301];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; cin>>nr>>nc;
    for1(i,0,nr) {
        for1(j,0,nc) {
            scanf("%d",&data[i][j]);
        }
    }

    subfunc(bool,isborder,(int i,int j,int dir)) {
        return i<0 || j<0 || i>=nr || j>=nc;
        /*if (!(i==0 || j==0 || i==nr-1 || j==nc-1)) return false;
        if (i==0 && j==0) {
            if (data[i][j]!=31) return data[i][j]==21 || data[i][j]==11 ||data[i][j]==12 || data[i][j]==22 || data[i][j]==11 ||data[i][j]==13; else {
                return dir==0 || dir==3;
            }
        }
        if (i==nr-1 && j==0) {
            if (data[i][j]!=31) return data[i][j]==21 || data[i][j]==13 ||data[i][j]==14 || data[i][j]==22 || data[i][j]==11 ||data[i][j]==13; else {
                return dir==2 || dir==3;
            }
        }
        if (i==0 && j==nc-1) {
            if (data[i][j]!=31) return data[i][j]==21 || data[i][j]==11 ||data[i][j]==12 || data[i][j]==22 || data[i][j]==12 ||data[i][j]==14; else {
                return dir==0 || dir==1;
            }
        }
        if (i==nr-1 && j==nc-1) {
            if (data[i][j]!=31) return data[i][j]==21 || data[i][j]==13 ||data[i][j]==14 || data[i][j]==22 || data[i][j]==12 ||data[i][j]==14; else {
                return dir==2 || dir==1;
            }
        }
        if (i==0) {
            if (data[i][j]!=31) return data[i][j]==21 || data[i][j]==11 ||data[i][j]==12; else {
                return dir==0;
            }
        }
        if (j==0) {
            if (data[i][j]!=31) return data[i][j]==22 || data[i][j]==11 ||data[i][j]==13; else {
                return dir==3;
            }
        }
        if (i==nr-1) {
            if (data[i][j]!=31) return data[i][j]==21 || data[i][j]==13 ||data[i][j]==14; else {
                return dir==2;
            }
        }
        if (j==nc-1) {
            if (data[i][j]!=31) return data[i][j]==22 || data[i][j]==12 ||data[i][j]==14; else {
                return dir==1;
            }
        }*/

    };

    subfunc(void,donext,(int &i,int &j,int &dir)) {
        switch(data[i][j]) {
        case 11:
            if (dir==2) {
                j--;
                dir = 3;
            } else {
                i--;
                dir = 0;
            }
            break;
        case 12:
            if (dir==2) {
                j++;
                dir = 1;
            } else {
                i--;
                dir = 0;
            }
            break;
        case 13:
            if (dir==0) {
                j--;
                dir = 3;
            } else {
                i++;
                dir = 2;
            }
            break;
        case 14:
            if (dir==0) {
                j++;
                dir = 1;
            } else {
                i++;
                dir = 2;
            }
            break;
        case 21:
            if (dir==2) {
                i++;
            } else {
                i--;
            }
            break;
        case 22:
            if (dir==1) {
                j++;
            } else {
                j--;
            }
            break;
        case 31:
            switch(dir) {
            case 0:
                i--;
                break;
            case 1:
                j++;
                break;
            case 2:
                i++;
                break;
            case 3:
                j--;
                break;
            }
            break;

        }
    };

    int rcount = 0;
    vector<int> rlen;

    //lai top
    for1(k,0,nc) {
        int i = 0;
        int j = k;
        int dir = 2; //NESW
        int len = 0;
        if (data[0][k]!=0 && (data[0][k]==21 || data[0][k]==11 ||data[0][k]==12 || data[0][k]==31)) {
            do {
                donext(i,j,dir);
                len++;
                /*if (len<=15) {
                    cerr<<i<<' '<<j<<' '<<dir<<endl;
                }*/
            } while (!isborder(i,j,dir));
            rlen.push_back(len);
            rcount++;
            //cerr<<endl;
        }
    }

    //lai left
    for1(k,0,nr) {
        int i = k;
        int j = 0;
        int dir = 1; //NESW
        int len = 0;
        if (data[i][j]!=0 && (data[i][j]==22 || data[i][j]==11 ||data[i][j]==13 || data[i][j]==31)) {
            do {
                donext(i,j,dir);
                len++;
                /*if (len<=15) {
                    cerr<<i<<' '<<j<<' '<<dir<<endl;
                }*/
            } while (!isborder(i,j,dir));
            rlen.push_back(len);
            rcount++;
            //cerr<<endl;
        }
    }

    //lai right
    for1(k,0,nr) {
        int i = k;
        int j = nc-1;
        int dir = 3; //NESW
        int len = 0;
        if (data[i][j]!=0 && (data[i][j]==22 || data[i][j]==12 ||data[i][j]==14 || data[i][j]==31)) {
            do {
                donext(i,j,dir);
                len++;
                /*if (len<=15) {
                    cerr<<i<<' '<<j<<' '<<dir<<endl;
                }*/
            } while (!isborder(i,j,dir));
            rlen.push_back(len);
            rcount++;
            //cerr<<endl;
        }
    }

    //lai bottom
    for1(k,0,nc) {
        int i = nr-1;
        int j = k;
        int dir = 0; //NESW
        int len = 0;
        if (data[i][j]!=0 && (data[i][j]==21 || data[i][j]==13 ||data[i][j]==14 || data[i][j]==31)) {
            do {
                donext(i,j,dir);
                len++;
                /*if (len<=15) {
                    cerr<<i<<' '<<j<<' '<<dir<<endl;
                }*/
            } while (!isborder(i,j,dir));
            rlen.push_back(len);
            rcount++;
            //cerr<<endl;
        }
    }

    sort(all(rlen));

    cout<<rcount/2<<endl;
    for(int i = 0;i<rlen.size();i+=2) printf("%d ",rlen[i]);


	return 0;
}
