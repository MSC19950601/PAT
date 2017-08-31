#include <cstdio>

const int Galleon = 17 * 29;
const int Sickle = 29;

int main() {
    int a1, b1, c1;
    int a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    int P = a1 * Galleon + b1 * Sickle + c1;
    int A = a2 * Galleon + b2 * Sickle + c2;
    int charge = A - P;
    if (charge < 0){
        printf("-");
        charge = -charge;
    }
    printf("%d.%d.%d", charge / Galleon, charge % Galleon / Sickle , charge % Sickle);
    return 0;
}