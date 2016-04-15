#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n[10];
    int found[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int count = 0;
    scanf("%d",&n[0]);
    scanf("%d",&n[1]);
    scanf("%d",&n[2]);
    scanf("%d",&n[3]);
    scanf("%d",&n[4]);
    scanf("%d",&n[5]);
    scanf("%d",&n[6]);
    scanf("%d",&n[7]);
    scanf("%d",&n[8]);
    scanf("%d",&n[9]);
    for (int i = 0;i<10;i++) {
        int value = n[i]%42;
        if (value != found[0] && value != found[1] && value != found[2] && value != found[3] && value != found[4] && value != found[5] && value != found[6] && value != found[7] && value != found[8] && value != found[9]) {
            found[i] = value;
            count++;
        }
    }
    cout<<count;
    return 0;
}

