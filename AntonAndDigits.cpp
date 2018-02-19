#include <iostream>
#include <algorithm>    // std::min
#include <cstdio>

using namespace std;

int main() {
    int k_2,k_3,k_5,k_6;
    scanf("%d %d %d %d",&k_2,&k_3,&k_5,&k_6);

    // make256
    int numOf256 = min(k_2,min(k_5,k_6));
    k_2 -= numOf256;

    int numOf32 = min(k_2,k_3);

    printf("%d\n", (numOf256 * 256) + (numOf32 * 32));

    return 0;
}