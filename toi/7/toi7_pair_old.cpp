#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;

ll sum = 0;
//ll addcount = 0;
int firstindex = -1; // use smtree to find first index that < selected(b)
int n;

class smtree {
public:

    vector<ll> tree;
    vector<pii> data;

    void build(int treei,int start,int end) {
        if (start==end) {
            tree[treei] = data[start].second;
            //cerr<<"build "<<start<<endl;
        } else {
            int mid = (start+end)/2;
            build(2*treei,start,mid);
            build(2*treei+1,mid+1,end);
            tree[treei] = min(tree[2*treei],tree[2*treei+1]);
        }
    }

    /*void process(int treei,int start,int end,int selectedi) {
        if (start==end) {
            if (tree[treei] < data[selectedi].second && start > selectedi) {
                sum += data[start].first;
                addcount++;
                //cerr<<"add "<<selectedi<<' '<<start<<endl;
            }
        } else if (tree[treei] < data[selectedi].second && end>selectedi) {
            int mid = (start+end)/2;
            process(2*treei,start,mid,selectedi);
            process(2*treei+1,mid+1,end,selectedi);
        }
    }*/

    void process(int treei,int start,int end,int selectedi) {
        //if path left me , select dai (end>selected) kor select mun
        if (start==end) {
            firstindex = start;
        } else {
            int mid = (start+end)/2;
            if (mid>selectedi) {
                //choose path left if min ok
                if (tree[2*treei] < data[selectedi].second) {
                    process(2*treei,start,mid,selectedi);
                } else {
                    if (tree[2*treei+1] < data[selectedi].second) {
                        process(2*treei+1,mid+1,end,selectedi);
                    }
                }
            } else {
                if (tree[2*treei+1] < data[selectedi].second) {
                    process(2*treei+1,mid+1,end,selectedi);
                }
            }
        }
    }

    smtree(vector<pii> &v) {
        data.resize(v.size());
        tree.resize(4*n);
        data = v;
        /*for1(i,0,n) {
            data[i] = v[i].second;
        }*/
        build(1,0,n-1);
    }
};



int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
     scanf("%d",&n);
    vector<pii> data(n);
    for1(i,0,n) scanf("%d %d",&data[i].first,&data[i].second);

    sort(all(data),[](pii a,pii b) {
         if (a.first<b.first) return true;
         if (a.first>b.first) return false;

         return a.second<b.second;
    });

    smtree sm(data);

    /*cerr<<"Debug:"<<endl;
    for1(i,0,n) {
        cerr<<i<<' '<<data[i].first<<' '<<data[i].second<<endl;
    }

    cerr<<endl;*/

    //build dp base case
    vector<ll> dp(n);
    vector<ll> addcount(n);
    dp[n-1] = 0;
    addcount[n-1] = 0;

    for(int i = n-2;i>=0;i--) {
        sm.process(1,0,n-1,i);

        cout<<firstindex<<endl;

        if (firstindex == -1) {
            dp[i] = 0;
            addcount[i] = 0;
            firstindex = -1;
            continue;
        }
        //cerr<<i<<' '<<addcount<<endl;
        //sum += data[i].first*addcount;
        //addcount = 0;

        firstindex = -1;
    }




    //sort by first ... if sort second 1 2 3 4 5 then if no select minb(i+1,...) >= selected(b) then bypass start at .... -> start at i+1
    //build segment tree (min query)
    //(change) if yung min(b) < selected(b) u choose path tor jon kar tung tung end (start at (first index a>selected(a)) -> end (change)
    // por tung end + a kong tua nun kow sum

    // use smtree to find first index that < selected(b)
    //optimize more by dp ... tum juk bottom    , dp[i] = sigma a that ok with it from i -> end
                                            //  , addcount[i] = number of a that ok with it from i -> end
    //dp[i] = dp[j] + data[j].first ; j>i
    //ans[i] = ans[j] + 1 ; j>i
    //ans[i] = dp[i] + addcount[i]*data[i].first;

    //This is meaning of jod
    /*for1(i,0,n) {
        for1(j,0,n) {
            if (i==j) continue;
            if (data[i].first > data[j].first && data[i].second < data[j].second) {
                sum += data[i].first + data[j].first;
            }
        }
    }*/

    cout<<sum;

	return 0;
}
