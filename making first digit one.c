#include <stdio.h>

int main() {
    int x, y;
    printf("Enter Number: ");
    scanf("%d", &x);

    // Extracting the one's digit
    int ones = x % 10;

    // Forming the new number with the ten's digit as 1
    y = 10 + ones;

    printf("Result = %d\n", y);
    return 0;
}
