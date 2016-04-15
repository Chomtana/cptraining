//old compiler stl sort function cannot sort string

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;

/*
a = b return 0
a > b return 1
a < b return -1
*/
int compare(string a,string b) {
	int retn = 0;
	int alen = a.length();
	int blen = b.length();
	if (alen < blen) retn = -1;
	else if (alen > blen) retn = 1;
	int len = min(alen,blen);
	for (int i = 0;i<len;i++) {
		if (a[i] < b[i]) {retn = -1; break;}
		else if (a[i] > b[i]) {retn = 1; break;}
	}
	return retn;
}

//bug
void quicksort(vector<string> &arr,int left,int right) {
	int i = 0;
	int j = right;
	string pivot = arr[(left+right)/2];
	while (i <= j) {
		while (compare(arr[i],pivot) == -1) i++;
		while (compare(arr[j],pivot) == 1) j--;
		if (i <= j) {
			string tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
			i++;
			j--;
		}
	}	
	
	if (left < j) quicksort(arr,left,j);
	if (right > i) quicksort(arr,right,i);
}

void insertionsort(vector<string> &arr,int pos,string target) {
	if (pos < 0) { arr[0] = target; return; }
	if (compare(arr[pos],target) == 1) {
		arr[pos+1] = arr[pos];
		insertionsort(arr,pos-1,target);
	} else {
		arr[pos+1] = target;
	}
}

void insertionsort(vector<string> &arr) {
	for (int i = 1;i<arr.size();i++) insertionsort(arr,i-1,arr[i]);
}

int main() {
	cin >> n;
	vector<string> data;
	map<string,bool> datacontains;
	cin.ignore();
	for (int i = 0;i<n;i++) {
		string dummy = ""; getline(cin,dummy);
		if (!datacontains[dummy]) {
			data.push_back(dummy);
			datacontains[dummy] = true;
		}
	}
	
	insertionsort(data);
	
	for (int i = 0;i<data.size();i++) {
		cout << data[i] << endl;
	}
	
	//cout << compare("ma","mai");
	
    return 0;
}

