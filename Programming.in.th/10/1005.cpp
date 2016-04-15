#include <iostream>

using namespace std;

int seqstart = -1; //result -> sequence start
int seqend = -1; //result -> sequence end
int summax = -1; //max of sum

void findseq(int in[],int n) {

    int sum = 0;
    int currentsummax = 0; //max of sum for current start,end
    int seqstarttemp = -1;
    int seqendtemp = -1;
    for (int i = 0;i<n;i++) {
        int currentsum = sum+in[i];

        if (currentsum < 0) {

            if (currentsummax > summax) {
                summax = currentsummax;
                seqstart = seqstarttemp;
                seqend = seqendtemp;
            }

            seqstarttemp = -1;
            sum = 0;
        } else {
            if (seqstarttemp == -1) {
                seqstarttemp = i;
            }
            if (currentsum > currentsummax) {
                currentsummax = currentsum;
                seqendtemp = i;
            }
            sum = currentsum;
        }
    }
    if (currentsummax > summax) {
        summax = currentsummax;
        seqstart = seqstarttemp;
        seqend = seqendtemp; //end = final
    }
}

int main() {
    int n;
    cin >> n;
    int data[n];
    for (int i = 0;i<n;i++) {
        cin >> data[i];
    }
    findseq(data,n);
    //cout << seqstart << " " << seqend << "\n";
    if (seqstart != -1 && summax != 0) {
        for (int i = seqstart;i<=seqend;i++) {
            cout << data[i] << " ";
        }
        cout << "\n" << summax;
    } else {
        cout << "Empty sequence";
    }
    return 0;
}
;
