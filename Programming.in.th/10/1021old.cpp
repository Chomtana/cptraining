#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int max (int a,int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
    return 0;
}

int max (int input[]) {
    int current = -2;
    int result = -1;
    for (int i = 0;i<sizeof(input);i++) {
        current = max(input[i],current);
        if (current == input[i]) {
            result = i;
        }    
    }
    return result;
}    

int main() {
    int n;
    cin >> n;
    int data[300001] = {-1};
    int size = 0;
    for (int i = 0;i<=n;i++) {
        string in = "";
        getline(cin,in);
        if (in[0] == 'P') {
            data[size] = atoi(in.substr(2,in.length()).c_str());
            /*if (data[size] == 0) {
                data[size] = -1;
            }*/   
            size++;
        }
        else if (in[0] == 'Q') {
            /*if (data[max(data)] == -1) {
                data[max(data)] = 0;
            } else if (data[max(data)] == 0) {
                data[max(data)] = -1;
            }*/   
            cout << data[max(data)] << "\n";
            data[max(data)] = 0;
        }    
    }
    //system("pause");
    return 0;
}

