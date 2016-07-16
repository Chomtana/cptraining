#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int x[9], TC, lineCounter,first,numm;
int y[92][9],z[9];
long long int cost=0,mincost;
bool place(int queen, int row) {
    for (int prev = 1; prev <= queen - 1; prev++) // check previously placed queens
        if (x[prev] == row || (abs(x[prev] - row) == abs(prev - queen)))
            return false; // an infeasible solution if share same row or same diagonal
    return true;
}
void NQueens(int queen) {

    for (int row = 1; row <= 8; row++)
        if (place(queen, row)) { // if can place this queen at this row?
            x[queen] = row; // put this queen in this row
            if (queen == 8 ) {//solution is found
                for (int c = 1; c<= 8; c++){//copy result
                    y[numm][c]=x[c];
                }
                numm++;
            }
            else
                NQueens(queen + 1); // recursively try next position
        } }

int main() {
	ios::sync_with_stdio(false);



    int i, TCcounter;
    numm=0;
    NQueens(1); // generate all possible 8! candidate solutions
    for (TCcounter=1; TCcounter<=1001; TCcounter++){

        for (i=1; i<=8; i++) {
            cin>>z[i];
        }
        first=0;



        for (int n=0; n<92; n++) {//for each of 92 solutions
            cost=0;
            for (i=1; i<=8; i++) {
            if(y[n][i]!=z[i])
                cost++;
            }
            if (first==0) {
                mincost=cost;
                first++;
            }
        	else if(cost<mincost){
                mincost=cost;
            }
			/*if (cost==2) {
				//for (i=1; i<=8; i++) cout<<y[n][i]<<' ';
				cout<<n;
				cout<<endl;
			}*/
        }

        printf("Case %i: %lld\n",TCcounter,mincost);

    }//for TCcounter
    return 0;
}
