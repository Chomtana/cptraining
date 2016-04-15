#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a,b;
    scanf("%lf %lf",&a,&b);
    //double ad = (double) a;
    //double bd = (double) b;
    printf("%f",sqrt(a*a+b*b));
    return 0;
}

