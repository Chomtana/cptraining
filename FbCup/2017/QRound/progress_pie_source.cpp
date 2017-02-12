#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main () {
	int t, o;
	float p,x,y,mp,ml;
	scanf("%d",&t);
	for (int i=1; i<=t; i++) {
		scanf("%f %f %f",&p,&x,&y);
		if (pow(x-50, 2) + pow(y-50, 2) > 2500) {
			o = 0;
		} else if (x==50) {
			if(y>=0) {
				o = 0;
			} else {
				if(p>=50) {
					o = 0;
				}
				else {
					o = 1;
				}
			}
		} else {
			ml = M_PI/50*(25-p);
			if (x > 50) {
				mp = atan((y-50)/(x-50));
			} else {
				mp = -M_PI/2 - atan((y-50)/(x-50));
			}
			if (mp <= ml) {
				o = 0;
			} else {
				o = 1;
			}
		}
		if (o == 0) {
			printf("Case #%d: white\n",i);
		} else {
			printf("Case #%d: black\n",i);
		}
	}
}
