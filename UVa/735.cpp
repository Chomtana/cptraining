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

bool possible(int i) {
    if (i==0) return true;
    if (i==50) return true;
    if (i>=1&&i<=20) return true;
    if (i%2==0&&i/2>=1&&i/2<=20) return true;
    if (i%3==0&&i/3>=1&&i/3<=20) return true;
    return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n;
    vector<int> score;
    for1(i,0,61) {
        if(possible(i)) score.push_back(i);
    }
    //cerr<<score.size();
    while (cin>>n,n>0) {
        int need = n;
        int pc=0;
        int cc=0;
        for1(ii,0,score.size()) {
            int i = score[ii];
            if (i>need) break;
            for1(jj,0,score.size()) {
                int j = score[jj];
                if (i+j>need) break;
                for1(kk,0,score.size()) {
                    int k = score[kk];
                    if(i+j+k>need) break;
                    //if (possible(i) && possible(j) && possible(k)) {
                        if (i+j+k==need) {
                            //cerr<<i<<' '<<j<<' '<<k<<endl;
                            pc++;
                            if (k>=j && j>=i) {
                                cc++;
                            }
                        }
                    //}
                }
            }
        }

        if (pc>0) {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,cc);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,pc);

        } else {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
        }
        printf("**********************************************************************\n");
    }
    printf("END OF OUTPUT\n");
	return 0;
}
