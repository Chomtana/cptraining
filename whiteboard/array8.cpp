#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    double kebsum=0,midsum=0,finalsum=0,allsum = 0;
    int kebmax=-1,midmax=-1,finalmax=-1,allmax = -1;
    int kebmin=1E9,midmin=1E9,finalmin=1E9,allmin = 1E9;
    int studentsum[n];
    for1(i,0,n) studentsum[i]=0;
    for1(i,0,n) {
        int a,b,c; cin>>a>>b>>c;
        if (a>60 || b>20 || c>20) {
            cout<<"!! Invalid score !!"; return 1;
        }
        studentsum[i] = a+b+c;
        kebsum += a;
        midsum += b;
        finalsum += c;
        allsum += studentsum[i];
        kebmax = max(kebmax,a);
        midmax = max(midmax,b);
        finalmax = max(finalmax,c);
        allmax = max(allmax,studentsum[i]);
        kebmin = min(kebmin,a);
        midmin = min(midmin,b);
        finalmin = min(finalmin,c);
        allmin = min(allmin,studentsum[i]);

    }
    printf("Average keep score : %.2f\n",kebsum/double(n));
    printf("Max keep score : %d\n",kebmax);
    printf("Min keep score : %d\n",kebmin);
    printf("Average mid score : %.2f\n",midsum/double(n));
    printf("Max mid score : %d\n",midmax);
    printf("Min mid score : %d\n",midmin);
    printf("Average final score : %.2f\n",finalsum/double(n));
    printf("Max final score : %d\n",finalmax);
    printf("Min final score : %d\n",finalmin);
    printf("Average score : %.2f\n",allsum/double(n));
    printf("Max score : %d\n",allmax);
    printf("Min score : %d\n",allmin);

    double studentxbar = 0;
    for1(i,0,n) {
        studentxbar += studentsum[i];
        //printf("Sum of student %d score : %d\n",i+1,int(studentsum[i]));
    }
    studentxbar /= double(n);
    double sd = 0;
    for1(i,0,n) {
        sd += (studentsum[i]-studentxbar)*(studentsum[i]-studentxbar);
    }
    sd /= double(n);
    sd = sqrt(sd);
    printf("SD : %.2f",sd);
	return 0;
}
