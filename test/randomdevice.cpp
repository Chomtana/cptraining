#include <random>
#include <iostream>
#include <ctime>
#include <windows.h>

#define random(s,e) uniform_int_distribution<long long>(s,e)(eng)

using namespace std;

typedef uniform_int_distribution<long long> random;

int main()
{
    default_random_engine eng(time(0));
    while (true) {
        cout<<random(1,80)<<endl;
        Sleep(100);
    }
}
