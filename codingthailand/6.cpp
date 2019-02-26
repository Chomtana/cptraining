#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
  
int count( int S[], int m, int n ) 
{ 
    int i, j, x, y; 
  
    // We need n+1 rows as the table is constructed  
    // in bottom up manner using the base case 0 
    // value case (n = 0) 
    int table[n+1][m]; 
     
    // Fill the enteries for 0 value case (n = 0) 
    for (i=0; i<m; i++) 
        table[0][i] = 1; 
  
    // Fill rest of the table entries in bottom  
    // up manner   
    for (i = 1; i < n+1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            // Count of solutions including S[j] 
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0; 
  
            // Count of solutions excluding S[j] 
            y = (j >= 1)? table[i][j-1]: 0; 
  
            // total count 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m-1]; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int i, j; 
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 500}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 4000; 
    printf("%d ", count(arr, m, n)); 
    //getchar(); 
    return 0; 
} 