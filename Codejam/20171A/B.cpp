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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        cout<<"Case #"<<_<<": ";
        int ni,np; cin>>ni>>np;
        vector<int> data(ni); for1(i,0,ni) cin>>data[i];
        vector<vector<int>> want(ni,vector<int>(np));
        for1(i,0,ni) {
            for1(j,0,np) {
                cin>>want[i][j];
            }
        }

        subfunc(bool,isok,(int a,int b)) {
            long double i = (long double)(a);
            long double j = (long double)(b);
            long double res = i/j*100;
            return res>=90 && res<=110;
        };

        int res = 0;

        vector<vector<int>> supercurr(np);
        vector<bool> possible(np,true);

        for1(i,0,ni) {
            vector<bool> thisinter(np,false);
            for1(j,0,np) {
                bool onecase = true;
                vector<int> curr;
                int mul = want[i][j]/data[i];
                if (!isok(want[i][j],mul*data[i])) {
                    mul++;
                    if (!isok(want[i][j],mul*data[i])) {
                        //cout<<j<<' ';
                        if (i==0) {
                            possible[j] = false;
                        }
                        continue;
                    }
                }
                //cout<<endl;

                curr.push_back(mul);

                int k = mul+1;
                while (isok(want[i][j],k*data[i])) {
                    curr.push_back(k);
                    k++;
                }

                k = mul-1;
                while (k>0 && isok(want[i][j],k*data[i])) {
                    curr.push_back(k);
                    k--;
                }


                if (i==0) {
                    supercurr[j] = curr;
                    if (ni==1) {
                        res++;
                    }
                } else {
                    //sort(all(supercurr));
                    sort(all(curr));
                    for1(l,0,np) {
                        if (!possible[l]) continue;
                        vector<int> interres(min(curr.size(),supercurr[l].size()));
                        sort(all(supercurr[l]));
                        interres.resize(set_intersection(all(supercurr[l]),all(curr),interres.begin())-interres.begin());
                        if (interres.size()!=0) {
                            thisinter[l] = true;
                            if (i == ni-1) {
                                res++;
                            }
                            break;
                        }
                    }
                }
            }
            if (i!=0) {
                possible = thisinter;
            }
        }

        cout<<res<<endl;
    }
	return 0;
}
