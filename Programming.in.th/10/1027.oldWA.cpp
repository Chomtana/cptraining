#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int getmaxindex (int in[]) {
    int currmax = -1;
    int result = 0;
    for (int i = 0;i<8;i++) {
        if (in[i] > currmax) {
            currmax = in[i];
            result = i;
        }    
    }
    return result;    
}

int getminindex (int in[],bool vote[]) {
    int currmin = 30001;
    int result = 0;
    int count = 0;
    for (int i = 0;i<8;i++) {
        if (in[i] < currmin && vote[i] == true) {
            currmin = in[i];
            result = i;
            count++;
        }    
    }
    if (count > 1) {
        return result;
    }
    return -1;      
}    

int main() {
    int currindex = 0;
    int score[8] = {0};
    bool lose[8] = {false,false,false,false,false,false,false};
    int playercount = 7;
    while (true) {
        char in[10002];
        scanf("%s",&in);
        int len = strlen(in);
        bool vote[8] = {false,false,false,false,false,false,false};
        if (in[0] == '!') {
            break;
        } else {
            for (int i = 0;i<len;i++) {
                if (!lose[in[i]-65]) {
                    score[in[i]-65]++;
                    vote[in[i]-65] = true;
                }    
            }
            int left = getminindex(score,vote);
            if (left != -1 && playercount > 1) {
                if (!lose[left]) {
                    playercount--;
                }    
                lose[left] = true;
            }       
        }     
    }
    cout << playercount << "\n";
    for (int i = 0;i<playercount;i++) {
        currindex = getmaxindex(score);
        cout << (char)(currindex+65) << " " << score[currindex] << "\n";
        score[currindex] = -1;
    }    
    system("pause");
    return 0;
}

