#include <bits/stdc++.h>

using namespace std;

vector< vector<char> > data;
int nrow,ncol;
int score = 0;

void scanFloat();
void destroy(int i,int j);
void toBottom(int row,int col);

void destroy(int i,int j) {
    bool selfdestroy = false;
    char c = data[i][j];
    if (i-1>=0 && data[i-1][j]==c) {
        data[i-1][j] = '-';
        data[i][j] = '-';
        score += 5;
        selfdestroy = true;
    }
    if (i+1<nrow && data[i+1][j]==c) {
        data[i+1][j] = '-';
        data[i][j] = '-';
        score += 5;
        selfdestroy = true;
    }
    if (j-1>=0 && data[i][j-1]==c) {
        data[i][j-1] = '-';
        data[i][j] = '-';
        score += 5;
        selfdestroy = true;
    }
    if (j+1<ncol && data[i][j+1]==c) {
        data[i][j+1] = '-';
        data[i][j] = '-';
        score += 5;
        selfdestroy = true;
    }
    if (selfdestroy) score += 5;
    scanFloat();
}

void toBottom(int row,int col) {
    char c = data[row][col];
    int i = 0;
    for (i = row+1;i<nrow;i++) {
        if (data[i][col] == '-') {
            data[i-1][col] = '-';
            data[i][col] = c;
        } else {
            break;
        }
    }
    if (i>0) destroy(i-1,col);
}

void scanFloat() {
    for (int i = 0;i<nrow-1;i++) {
        for (int j = 0;j<ncol;j++) {
            if (data[i][j]!='-' && data[i][j]!='#' && data[i+1][j] == '-') toBottom(i,j);
        }
    }
}

int main() {
    cin>>nrow>>ncol;
    data.resize(nrow);
    fill(data.begin(),data.end(),vector<char>(ncol));
    for (int i = 0;i<nrow;i++) {
        for (int j = 0;j<ncol;j++) {
            cin >> data[i][j];
        }
    }
    
    int n; cin>>n;
    while (n--) {
        int row,col;cin>>row>>col;
        char op;cin>>op;
        
        if (data[row][col] == '#' || data[row][col] == '-') {
            score -= 5;
            continue;
        }
        
        switch (op) {
            case 'L':
                if (col-1>=0 && data[row][col-1] == '-') {
                    data[row][col-1] = data[row][col];
                    data[row][col] = '-';
                    toBottom(row,col-1);
                } else score-=5;
                break;
            case 'R':
                if (col+1<ncol && data[row][col+1] == '-') {
                    data[row][col+1] = data[row][col];
                    data[row][col] = '-';
                    toBottom(row,col+1);
                } else score-=5;
                break;
        }
        
    }
    
    cout<<score<<endl;
    for (int i = 0;i<nrow;i++) {
        for (int j = 0;j<ncol;j++) {
            cout << data[i][j] << " ";
        }cout<<endl;
    }
    
    return 0;
}