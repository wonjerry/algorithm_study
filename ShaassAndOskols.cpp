#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);

    int *wires = new int[n + 1];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &wires[i]);
    }

    scanf("%d", &m);

    int wire, bird, upperWire, lowerWire, goToupperBird, goTolowerBird;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &wire, &bird);

        upperWire = wire - 1;
        lowerWire = wire + 1;
        goToupperBird = bird - 1;
        goTolowerBird = wires[wire] - bird;

        if(upperWire != 0 && goToupperBird > 0) {
            wires[upperWire] += goToupperBird;
        }

        if(lowerWire != n + 1 && goTolowerBird > 0) {
            wires[lowerWire] += goTolowerBird;
        }

        wires[wire] = 0;
    }

    for(int i = 1; i <= n; i++) {
        printf("%d\n", wires[i]);
    }

    return 0;
}