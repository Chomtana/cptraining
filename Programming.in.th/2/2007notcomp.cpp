#include <iostream>
#include <string>
#include <vector>
#include <map>

#define tocharcounti(c) (( (c) <'a')? (c) -'A'+26: (c) -'a');

using namespace std;

vector<int> targetcharcount(52);
int targetl,inl;
string target;
string in;

vector<int> getincharcount(int start,int end) {
    vector<int> result(52);
    for (int i = start;i<end;i++) {
        int incharcounti = tocharcounti(in[i]);
        result[incharcounti]++;
    }
    return result;
}

bool charcountcompare(vector<int> incharcount) {
    bool result = true;
    for (int i = 0;i<targetl;i++) {
        if (incharcount[i] != targetcharcount[i]) {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
    cin >> targetl >> inl;
    cin >> target;
    cin >> in;
    
    //target charcount
    for (int i = 0;i<targetl;i++) {
        int targetcharcounti = tocharcounti(target[i]);
        targetcharcount[targetcharcounti]++;
    }
    
    int result = 0;
    for (int start = 0;start<=inl-targetl;start++) {
        int end = start+targetl;
        vector<int> incharcount = getincharcount(start,end);
        if (charcountcompare(incharcount)) {
            result++;
        }
    }
    cout << result;
    return 0;
}