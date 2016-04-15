#include <stdio.h>
#include <iostream>

using namespace std;

int data[9] = {0};

int sumnot (int not1,int not2) {
    int result = 0;
    for (int i = 0;i<9;i++) {
        if (i != not1 && i != not2) {
            result += data[i];
        }    
    }
    return result;
}

void printresult (int not1,int not2) {
    for (int i = 0;i<9;i++) {
        if (i != not1 && i != not2) {
            cout << data[i] << "\n";
        }    
    }
}    

int main() {
    for (int i = 0;i<9;i++) {
        scanf("%d",&data[i]);
    }
    for (int i = 0;i<9;i++) {
        for (int i2 = 0;i2<8;i2++) {
            if (i2<i) {
                if (sumnot(i,i2) == 100) {
                    printresult(i,i2);
                    //system("pause");
                    return 0;
                }    
            } else {
                if (sumnot(i,i2+1) == 100) {
                    printresult(i,i2+1);
                    //system("pause");
                    return 0;
                }
            }    
        }    
    }    
    return 0;
}

