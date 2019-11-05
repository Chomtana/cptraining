// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>

typedef pair<int,int> pii;
typedef pair<pii,pii> piii;

deque<int> q;

int nullvar = -1.1e9;

int var1 = nullvar;
int var1last = nullvar;
int var2 = nullvar;
int var2last = nullvar;
int front = 0;
//int currres = 0;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int res = 0;

    for(int i = 0;i<(int)A.size();i++) {
        if (var1 == nullvar) {
            q.push_back(A[i]);
            var1 = A[i];
            var1last = i;
            //currres++;
        } else if (var2 == nullvar) {
            q.push_back(A[i]);
            var2 = A[i];
            var2last = i;
            //currres++;
        } else if (var1 == A[i]) {
            q.push_back(A[i]);
            var1last = i;
            //currres++;
        } else if (var2 == A[i]) {
            q.push_back(A[i]);
            var2last = i;
            //currres++;
        } else {
            if (var1last < var2last) {
                while (front <= var1last) {
                    q.pop_front();
                    front++;
                }
                q.push_back(A[i]);
                var1last = i;
                var1 = A[i];
            } else {
                while (front <= var2last) {
                    q.pop_front();
                    front++;
                }
                q.push_back(A[i]);
                var2last = i;
                var2 = A[i];
            }
        }

        res = max(res, i-front+1);
    }

    return res;
}
