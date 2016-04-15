#include <bits/stdc++.h>
#define comp(a,b) data[i][j]==get((a),(b))
#define comp1(a,b) if (comp(i+((a)),j+((b)))) { visited[(a)+2][(b)+2]=true; around++;
#define comp2(a,b) if (!visited[(a)][(b)]) { around+=comp(i+((a)),j+((b))); visited[(a)+2][(b)+2]=true;}

using namespace std;

int data[20][20]; //row col
int n;

int get(int i,int j) {
    if (i<0 || j<0 || i>=n || j>=n) return -1;
    return data[i][j];
}

int main() {
    cin>>n;
    
    for (int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>data[i][j];
        }
    }
    
    int result = 0;
    for (int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            int around = 0; //size of floor : around == 2 : ok
            /*around += comp(i-1,j-1);
            around += comp(i-1,j+1);
            around += comp(i+1,j-1);
            around += comp(i+1,j+1);
            around += comp(i-1,j);
            around += comp(i+1,j);
            around += comp(i,j-1);
            around += comp(i,j+1);
            if (comp(i-2,j) && comp(i+2,j) && comp(i,j+2) && comp(i,j-2)) around = -1; //if around==2 , it will make line(len=3) : force not enter if*/
            bool visited[5][5]; //+2 (-2:0,-1:1,2:4)
            for (int i = 0;i<5;i++) for(int j = 0;j<5;j++) visited[i][j]=false;
            comp1(-1,0)
                if (comp(i-2,j)) { //make line(len=3) so continue
                    continue;
                }
                comp2(-1,-1)
                comp2(-1,1)
            }
            comp1(1,0)
                if (comp(i+2,j)) { //make line(len=3) so continue
                    continue;
                }
                comp2(1,-1)
                comp2(1,1)
            }
            comp1(0,-1)
                if (comp(i,j-2)) { //make line(len=3) so continue
                    continue;
                }
                comp2(1,-1)
                comp2(-1,-1)
            }
            comp1(0,1)
                if (comp(i,j+2)) { //make line(len=3) so continue
                    continue;
                }
                comp2(1,1)
                comp2(-1,1)
            }
            if (around == 2) {
                //check form of floor (let i,j = intersection of two line)
                if (comp(i,j+1) && comp(i+1,j)) result++;
                else if (comp(i,j+1) && comp(i-1,j)) result++;
                else if (comp(i,j-1) && comp(i+1,j)) result++;
                else if (comp(i,j-1) && comp(i-1,j)) result++;
            }
        }
    }
    cout<<result;
    return 0;
}

/*
First try wrong case:
1
 11
 1
*/