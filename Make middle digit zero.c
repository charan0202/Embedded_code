#include <stdio.h>

int main() {
    int x, y;
    printf("Enter a three-digit number: ");
    scanf("%d", &x);

    // Ensure the number is three digits
    if (x >= 100 && x <= 999) {
        // Extract hundreds and ones digits
        int hundreds = x / 100;
        int ones = x % 10;

        // Construct the new number with the tens digit set to 0
        y = hundreds * 100 + ones;

        printf("Result = %d\n", y);
    } else {
        printf("Please enter a three-digit number.\n");
    }

    return 0;
}

