#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

struct type {
	double q,p; //q=current supply , p=price per unit
};

bool ss(type a,type b) {
	return a.p<b.p;
}

int main() {
	int k; scanf("%d",&k);
	type data[k];
	for1(i,0,k) {
		double p,q; scanf("%lf%lf",&p,&q);
		data[i].q = q;
		data[i].p = p/q;
	}
	sort(data,data+k,ss);

	int c=0; //current not q=0 index

	int t; scanf("%d",&t);
	while(t--) {
		double in; scanf("%lf",&in);
		double out = 0;
		redo:
		if (data[c].q>=in) {
			out+=in*data[c].p;
			data[c].q-=in;

		} else {
			out+=data[c].q*data[c].p;
			in -= data[c].q;
			data[c].q=0;
			c++;
			goto redo;
		}

		printf("%.3f\n",out);
	}

	return 0;
}
