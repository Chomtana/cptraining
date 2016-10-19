#include <bits/stdc++.h>

using namespace std;

/*
sort algorithm:
1.sort by subset point
    subset point: number of character match maxlens start from index 0
        Ex:
        maxlens =   abcdefghijk
                    f : 0
                    fbcdef : 0
                    a : 1
                    abc : 3
                    abcdx : 4
                    def : 0
                    abcdefghijx : 10
2.sort lexicographically (lexicographical_compare)
*/

struct type {
    string s;
    int subset = 0;
};

int maxlen = -1;
string maxlens;

bool compfunc(type a,type b) {
    if (a.subset < b.subset) return true;
    if (a.subset > b.subset) return false;

    return lexicographical_compare(a.s.begin(),a.s.end(),b.s.begin(),b.s.end());
}

int main() {
    int n; cin>>n;
    vector<type> data(n);
    for (int i = 0;i<n;i++) {
        cin >> data[i].s;

        if ((int)data[i].s.length() > maxlen) {
            maxlen = data[i].s.length();
            maxlens = data[i].s;
        }
    }

    for (int i=0;i<n;i++) {
        int j=0;

        while (j<data[i].s.length() && j<maxlens.length() && data[i].s[j]==maxlens[j]) { j++;}
        data[i].subset = j;
        //cout << maxlens << ' ' << j << '\n';

    }

    sort(data.begin(),data.end(),compfunc);

    //for (int i = 0;i<n;i++) {cout << data[i].s << "\n";}

    vector<int> printer;
    ostringstream oss;
    int result = 0;
    for (int i=0;i<n;i++) {
        int jstart = 0;
        while (jstart<data[i].s.length() && jstart<printer.size() && data[i].s[jstart]==printer[jstart]) {jstart++;}
        int printersize = printer.size();
        for (int j=jstart;j<printersize;j++) {oss<<'-'<<'\n';printer.pop_back();result++;}

        for (int j=jstart;j<data[i].s.length();j++) {
            oss << data[i].s[j] << '\n';
            result++;
            printer.push_back(data[i].s[j]);
        }

        oss << 'P' << '\n';
        result++;
    }

    cout << result << '\n'; cout << oss.str();

    return 0;
}
