#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int count(string s,int start,char c) {
  int n = 0;

  for (int i = start; i < s.length(); i++)
    if (s[i] == c) n++;

  return n;
}

int max(int a,int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int n = 10000;
    long long aaa = 0;
    int data[100001];
    //string data;
    string dummy;
    long long result = 0;
    //cin >> n;
    for (int i = 0;i<n;i++) {
		//cin >> data[i];
		data[i] = 999;
    }
    for (int i = 0;i < n;i++) {
        int n1 = data[i]/100;
        int n2 = (data[i]%100)/10;
        int n3 = data[i]%10;
        for (int i2 = i+1;i2<n;i2++) {
            int n4 = data[i2]/100;
            int n5 = (data[i2]%100)/10;
            int n6 = data[i2]%10;
            if (n1 == n4 || n2 == n5 || n3 == n6) {
                result++;
            }
        }
    }
    /*for (int i = 0;i<n;i++) {
        char n1 = data.substr((i*3),1).c_str()[0];
        char n2 = data.substr((i*3)+1,1).c_str()[0];
        char n3 = data.substr((i*3)+2,1).c_str()[0];
        for (int i2 = i+1;i2<n;i2++) {

        }
    }*/
    printf("%lld",result);
    return 0;
}

