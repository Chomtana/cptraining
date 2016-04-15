#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

map<long long int,long long int> pfunion; //[a] = n
map<long long int,bool> pfunionkeycontains;
vector<long long int> pfunionkey; //[...] = a

void pf(long long int n) { //prime factorization
    map<long long int,long long int> result; //a^n*a^n*a^n*... -> result[a] = n
    vector<long long int> resultkey; //resultkey[...] = a
    for (long long int i = 2;i<=n;i++) {
        if (n%i == 0) {
            result[i]++;
            resultkey.push_back(i);
            n /= i;
            i = 1;
        }
    }
    //return result;

    for (int i = 0;i<resultkey.size();i++) {
        pfunion[resultkey[i]] = max(result[resultkey[i]],pfunion[resultkey[i]]);
        if (!pfunionkeycontains[resultkey[i]]) {
            pfunionkey.push_back(resultkey[i]);
            pfunionkeycontains[resultkey[i]] = true;
        }
    }
}

int main () {
    int n;
    cin >> n;
    for (int i = 0;i<n;i++) {
        long long int in;
        cin >> in;
        pf(in);
    }
    long long int multiply = 1;
    for (int i = 0;i<pfunionkey.size();i++) {
         multiply *= pow(pfunionkey[i],pfunion[pfunionkey[i]]);
    }
    cout << multiply;
    return 0;
}
