#include <bits/stdc++.h>
#define get(i,j) geta(data,(i),(j))
#define isBlock(i,j) isBlocka(data,(i),(j))

using namespace std;

int n = 1000;

char geta(vector< vector<char> > &v,int i,int j) {
    if (i < 0 || i >= 2 || j < 0 || j>=n) return 'X';
    return v[i][j];
}

void putGuard(vector< vector<char> > &data,int i,int j) {
    int _i = i,_j = j;
    data[i][_j] = '#';
    j--;
    while (get(i,j)!='X') {
        data[i][j] = '#';
        j--;
    }
    j=_j+1;
    while (get(i,j)!='X') {
        data[i][j] = '#';
        j++;
    }
    if (i==0) i=1;
    else if (i==1) i=0;
    data[i][_j] = '#';
}

bool isBlocka(vector< vector<char> > &data,int i,int j) {
    return (get(i,j)=='X' || get(i,j)=='#');
}

int main() {
    fstream fs("fb02.txt");
    ofstream ofs("fb02out.txt");
    int t;fs>>t;
    for (int _t=1;_t<=t;_t++) {
        fs>>n;
        vector< vector<char> > data(2);
        fill(data.begin(),data.end(),vector<char>(n));
        for (int i = 0;i<n;i++) {
            fs >> data[0][i];
            //if (i%10 == 0 || i%3 == 0 || i%5 == 0) data[0][i] = '.'; else data[0][i] = 'X';
        }
        for (int i = 0;i<n;i++) {
            fs >> data[1][i];
            //if (i%3 == 0) data[0][i] = '.'; else data[0][i] = 'X';
        }

        int result = 0;

        while (true) {

            bool end = true;

            //find intersection
            for (int i = 0;i<n;i++) {
                if (get(0,i)=='.' || get(1,i)=='.') end = false;

                if (get(0,i)!='X' && get(1,i)=='.' && isBlock(1,i-1) && isBlock(1,i+1)) {
                    putGuard(data,0,i);
                    result++;
                    //data[0][i] = 'G';
                }

                if (get(1,i)!='X' && get(0,i)=='.' && isBlock(0,i-1) && isBlock(0,i+1)) {
                    putGuard(data,1,i);
                    result++;
                    //data[1][i] = 'G';
                }

                /*hire = false;
                if ( (get(0,i-1)=='X'&&get(1,i+1)=='X') || (get(0,i+1)=='X'&&get(1,i-1)=='X')) {
                    putGuard(data,0,i);
                    result++;
                    data[0][i] = 'G';
                }

                hire = false;
                if ( (get(1,i-1)=='X'&&get(0,i+1)=='X') || (get(1,i+1)=='X'&&get(0,i-1)=='X')) {
                    putGuard(data,1,i);
                    result++;
                    data[0][i] = 'G';
                }*/
            }

            if (end) break;

            //rectangle
            for (int i = 0;i<n;i++) {
                bool hire = false;
                if (get(0,i)=='.' && get(1,i)=='.' && get(0,i+1)=='.' && get(1,i+1)=='.') {
                    //bool reverse = false;
                    //if (get(0,i-1)=='.' || get(1,i-1)=='.') reverse = true;

                    //if (!reverse) {
                        putGuard(data,0,i);
                        //data[0][i] = 'G';
                        do i++; while (get(1,i)=='.');
                        i--;
                        putGuard(data,1,i);
                        //data[1][i] = 'G';
                    //} else {

                    //}

                    result+=2;
                    //data[0][i] = 'G';
                }
                //cout << "aaa";
            }

            //find single
            for (int i = 0;i<n;i++) {
                if (get(0,i)=='.' && get(0,i+1) == '.') {
                    putGuard(data,0,i);
                    result++;
                    //data[0][i] = 'G';
                }
                if (get(1,i)=='.' && get(1,i+1) == '.') {
                    putGuard(data,1,i);
                    result++;
                    //data[1][i] = 'G';
                }
                if (get(0,i)=='.' && get(1,i) == '.') {
                    putGuard(data,0,i);
                    result++;
                    //data[0][i] = 'G';
                }
                if (get(0,i)=='.' && isBlock(0,i-1) && isBlock(0,i+1) && isBlock(1,i)) {
                    putGuard(data,0,i);
                    result++;
                    //data[0][i] = 'G';
                }
                if (get(1,i)=='.' && isBlock(1,i-1) && isBlock(1,i+1) && isBlock(0,i)) {
                    putGuard(data,1,i);
                    result++;
                    //data[1][i] = 'G';
                }

            }


        }

        /*for (int i = 0;i<n;i++) {
            cout<< data[0][i];
        }
        cout<<endl;
        for (int i = 0;i<n;i++) {
            cout<<data[1][i];
        }
        cout << endl;*/

        cout << "Case #" << _t << ": " << result << "\n";
        ofs << "Case #" << _t << ": " << result << "\n";
    }
    return 0;
}
