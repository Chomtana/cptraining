#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

double getave(double sum,double count) {
    if (count==0) return 0;
    return sum/count;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    cout<<"Input number of people : "; int n; cin>>n;
    int count[5];
    int sum[5];
    fill(count,count+5,0);
    fill(sum,sum+5,0);
    for1(i,0,n) {
        cout<<"People "<<i+1<<" : "; int age; cin>>age;
        if (age<15) {
            sum[0] += age;
            count[0]++;
        } else if (age<=20) {
            sum[1] += age;
            count[1]++;
        } else if (age<=40) {
            sum[2] += age;
            count[2]++;
        } else if (age<=60) {
            sum[3] += age;
            count[3]++;
        } else {
            sum[4] += age;
            count[4]++;
        }
    }
    cout<<"Children count : "<<count[0]<<endl;
    printf("Children average age : %.2f\n",getave(double(sum[0]),double(count[0])));
    cout<<"Teenager count : "<<count[1]<<endl;
    printf("Teenager average age : %.2f\n",getave(double(sum[1]),double(count[1])));
    cout<<"Begin adult count : "<<count[2]<<endl;
    printf("Begin adult average age : %.2f\n",getave(double(sum[2]),double(count[2])));
    cout<<"Middle count : "<<count[3]<<endl;
    printf("Middle average age : %.2f\n",getave(double(sum[3]),double(count[3])));
    cout<<"Old count : "<<count[4]<<endl;
    printf("Old average age : %.2f\n",getave(double(sum[4]),double(count[4])));
	return 0;
}
