#include <bits/stdc++.h>

using namespace std;

typedef vector< vector<char> > matrix;

int rown,coln;

bool isPossible(matrix data,string s,int pos,int i,int j,int dir) { //dir = UP LEFT DOWN RIGHT ; input is current not next (found 'x' at (2,2) input (2,2) not (2,3),(3,2),...)
    if (pos+1 >= s.length()) return true;
    if (i >= rown || j >= coln || i<0 || j<0 || pos<0) return false;
    switch (dir) {
        case 0: //UP
            if (i-1 >= 0 && s[pos+1] == data[i-1][j]) {
                if (isPossible(data,s,pos+1,i-1,j,dir)) return true;
            }
            break;
        case 1: //LEFT
            if (j-1 >= 0 && s[pos+1] == data[i][j-1]) {
                if (isPossible(data,s,pos+1,i,j-1,dir)) return true;
            }
            break;
        case 2: //DOWN
            if (i+1 < rown && s[pos+1] == data[i+1][j]) {
                if (isPossible(data,s,pos+1,i+1,j,dir)) return true;
            }
            break;
        case 3: //RIGHT
            if (j+1 < coln && s[pos+1] == data[i][j+1]) {
                if (isPossible(data,s,pos+1,i,j+1,dir)) return true;
            }
            break;
        case 4: //UP LEFT
            if (j-1 >= 0 && i-1 >= 0 && s[pos+1] == data[i-1][j-1]) {
                if (isPossible(data,s,pos+1,i-1,j-1,dir)) return true;
            }
            break;
        case 5: //UP RIGHT
            if (j+1 < coln && i-1 >= 0 && s[pos+1] == data[i-1][j+1]) {
                if (isPossible(data,s,pos+1,i-1,j+1,dir)) return true;
            }
            break;
        case 6: //DOWN LEFT
            if (j-1 >= 0 && i+1 < rown && s[pos+1] == data[i+1][j-1]) {
                if (isPossible(data,s,pos+1,i+1,j-1,dir)) return true;
            }
            break;
        case 7: //DOWN RIGHT
        	//cout << i << " " << j<< "\n";
            if (j+1 < coln && i+1 < rown && s[pos+1] == data[i+1][j+1]) {
                if (isPossible(data,s,pos+1,i+1,j+1,dir)) return true;
            }
            break;
    }
    
    return false;
}

int main() {
    cin>>rown>>coln;
    matrix data(rown);
    for(int i = 0;i<rown;i++) {
        vector<char> row(coln); data[i] = row;
        for (int j = 0;j<coln;j++) {
            cin >> data[i][j];
            data[i][j] = tolower(data[i][j]);
        }
    }
    
    int t; cin >> t;
    while (t--) {
        string s; cin>>s;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        //reverse(s.begin(),s.end());
        
        bool first = true;
        for(int i = 0;i<rown;i++) {
            for (int j = 0;j<coln;j++) {
                if (data[i][j] == s[0] && (isPossible(data,s,0,i,j,0) || isPossible(data,s,0,i,j,1) || isPossible(data,s,0,i,j,2) || isPossible(data,s,0,i,j,3) || isPossible(data,s,0,i,j,4) || isPossible(data,s,0,i,j,5) || isPossible(data,s,0,i,j,6) || isPossible(data,s,0,i,j,7))) {
                    cout << i << " " << j << "\n";
                    goto next;
                }
            }
        }
        
        next:
        continue;
    }
    return 0;
}