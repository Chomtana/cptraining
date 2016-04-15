#include <bits/stdc++.h>

using namespace std;

//Ignore number that >= 2^n
//End with 1 = odd only
//Start with 1
//must not prime (use seive for caching)

long long toBase(string s,int base) {
    long long res = 0;
    for (int i = 0;i<s.size();i++) {
        if (s[i]=='1') {
            res += pow(base,s.size()-i-1);
        }
    }
    return res;
}

long long isPrime(long long n) { //return first divisor (0 if prime)
    long long divisor = 0;
    for (long long i=2;i<=sqrt(n);i++) {
        if (n%i==0) {
            divisor = i;
            break;
        }
    }
    return divisor;
}

int main() {
    cout << fixed;
    int _____; cin>>_____;
    int n,j; cin>>n>>j;
    int printcount = 0;
    long long curr = pow(2,n-1)+1;
    long long ub = pow(2,n);
    if (n==1) curr=1;
    cout<<"Case #1:"<<endl;
    while (printcount<j && curr<ub) {
        bool ok = true; //for all not prime = true -> for some prime = false
        bitset<32> bs(curr);
        string s = bs.to_string().substr(32-n,n);
        long long value[11];
        for (int i = 2; i<=10;i++) {
            long long basecurr = toBase(s,i);
            long long divisor = isPrime(basecurr);
            if (divisor == 0) {
                goto next;
            } else {
                value[i]=divisor;
            }
        }
        printcount++; //this case : print
        cout<<s;
        for (int i = 2; i<=10;i++) {
            cout<<' '<<value[i];
        }
        cout<<endl;

        next: curr+=2;
    }
    return 0;
}



