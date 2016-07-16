#include <iostream>

using namespace std;

int main() {
	int x; float n; cin>>x>>n;
	if (x%5!=0 || x>n-0.5) {
		printf("%.2f",n);
		return 0;
	}

	printf("%.2f",(n-x)-0.5);

	return 0;
}
