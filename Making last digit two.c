#include <stdio.h>

int main() {
    int x, y;
    printf("Enter Number: ");
    scanf("%d", &x);

    // Ensure the number is three digits
    if (x >= 100 && x <= 999) {
        // Get the hundreds and tens part
        int hundreds = x / 10;
        // Make the one's digit as 2
        y = hundreds * 10 + 2;
        printf("Result = %d\n", y);
    } else {
        printf("Please enter a three-digit number.\n");
    }

    return 0;
}

