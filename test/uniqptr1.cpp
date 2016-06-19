#include <bits/stdc++.h>
#include <memory>

using namespace std;

struct type {
	int a,b;
};

type* po;

void f(int a,int b) {
	type t; t.a=a; t.b=b;
	po = &t;
}

int main() {

	unique_ptr<type> p;
	/*type *po;
	{
		type i;
		i.a=555;
		i.b=555;
		p = unique_ptr<type>(&i);
		po = &i;
		//*po = 888;

	}
	cout<<(*p).a<<endl;
	cout<<(*po).a;*/

	//type *po = f(555,666);
	f(555,666);
	cout<<(*po).b;
	return 0;
}
