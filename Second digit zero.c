#include <stdio.h>

int main() {
    int x, y;
    printf("Enter Number: ");
    scanf("%d", &x);

    // Extracting the digits
    int first_digit = x/10;           // Get the thousand's place digit
    int second_digit = x%10;  // Get the hundred's place digit

    y = x - second_digit;
    printf("Result = %d\n", y);
    return 0;
}

