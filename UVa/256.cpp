#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v[4];

void makev(string &s,ll y,int digit) {
    if (s.size()>digit) return;
    while (s.size()!=digit) {
        s = "0"+s;
    }
    int digit2 = digit/2;
    string sum1s = "";
    for (int i = 0;i<digit2;i++) {
        sum1s += s[i];
    }
    string sum2s = "";
    for (int i = digit2;i<digit;i++) {
        sum2s += s[i];
    }
    ll sum = atoi(sum1s.c_str())+atoi(sum2s.c_str());
    if (sum*sum == y) {
        v[digit/2-1].push_back(y);
    }
}

void printv(int digit) {
    char parg[8] = "%00lld\n";
    parg[2] = digit+'0';
    digit /= 2;
    digit -= 1;
    for(ll i : v[digit]) {

        printf(parg,i);
    }
}

int main() {
    ios::sync_with_stdio(false);

    for (ll x = 0;x<=10000;x++) {
        ll y = x*x;
        char s1[10];
        sprintf(s1,"%ld",y);
        string s(s1);
        makev(s,y,2);
        makev(s,y,4);
        makev(s,y,6);
        makev(s,y,8);
    }

    int n;
    while (cin>>n) {
        printv(n);
    }

    return 0;
}
