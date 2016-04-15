#include <bits/stdc++.h>
#define condition(aa,ab,ac,ba,bb,bc,ca,cb,cc) data[0][0]==(aa)&&data[0][1]==(ab)&&data[0][2]==(ac)&&data[1][0]==(ba)&&data[1][1]==(bb)&&data[1][2]==(bc)&&data[2][0]==(ca)&&data[2][1]==(cb)&&data[2][2]==(cc)

using namespace std;

char check(char data[3][3]) {
	if (		condition(' ',' ',' ',' ',' ','|',' ',' ','|')) return '1';
	else if (	condition(' ','_',' ',' ','_','|','|','_',' ')) return '2';
	else if (	condition(' ','_',' ',' ','_','|',' ','_','|')) return '3';
	else if (	condition(' ',' ',' ','|','_','|',' ',' ','|')) return '4';
	else if (	condition(' ','_',' ','|','_',' ',' ','_','|')) return '5';
	else if (	condition(' ','_',' ','|','_',' ','|','_','|')) return '6';
	else if (	condition(' ','_',' ',' ',' ','|',' ',' ','|')) return '7';
	else if (	condition(' ','_',' ','|','_','|','|','_','|')) return '8';
	else if (	condition(' ','_',' ','|','_','|',' ','_','|')) return '9';
	else if (	condition(' ','_',' ','|',' ','|','|','_','|')) return '0';
	return '0';
}

long long toi(string s) {
	stringstream ss(s);
	long long i; ss >> i;
	return i;
}

int main() {
	// your code goes here
	int n1,n2;cin>>n1>>n2;
	string s1="",s2="";
	string in1[3];
	string in2[3];
	cin.ignore();
	getline(cin,in1[0]);
	getline(cin,in1[1]);
	getline(cin,in1[2]);
	getline(cin,in2[0]);
	getline(cin,in2[1]);
	getline(cin,in2[2]);
	//cout << in2[0] << "\n"<<in2[1]<<endl<<in2[2];
	for (int _n1=0;_n1<n1;_n1++) {
		char in[3][3]; //row col
		for (int i = 0;i<3;i++) {
			for (int j = 0;j<3;j++) {
				in[i][j] = in1[i][_n1*3+j+_n1];
				//cout<<in[i][j];
			}//cout<<"\n";
		}
		
		s1+=check(in);
	}
	for (int _n2=0;_n2<n2;_n2++) {
		char in[3][3]; //row col
		for (int i = 0;i<3;i++) {
			for (int j = 0;j<3;j++) {
				in[i][j] = in2[i][_n2*3+j+_n2];
				//cout<<in[i][j];
			}//cout<<"\n";
		}
		
		s2+=check(in);
	}
	//cout << s1;
	cout << toi(s1)+toi(s2);
	return 0;
}