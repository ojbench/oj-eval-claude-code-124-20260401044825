#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
int occupied[MAXN]; // occupied[i] stores the number of occupied seats between station i and i+1

int main() {
    int x, k, p;
    scanf("%d %d %d", &x, &k, &p);

    // Initialize all segments as empty
    for (int i = 1; i < x; i++) {
        occupied[i] = 0;
    }

    for (int i = 0; i < p; i++) {
        int u, v, n;
        scanf("%d %d %d", &u, &v, &n);

        // Check if we can fulfill this order
        bool canFulfill = true;
        for (int j = u; j < v; j++) {
            if (occupied[j] + n > k) {
                canFulfill = false;
                break;
            }
        }

        if (canFulfill) {
            // Occupy the seats
            for (int j = u; j < v; j++) {
                occupied[j] += n;
            }
            printf("T\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
