#include <stdio.h>

int main() {
    int x, y;
    printf("Enter Number: ");
    scanf("%d", &x);

    // Extracting the digits
    int first_digit = x / 1000;           // Get the thousand's place digit
    int second_digit = (x / 100) % 10;    // Get the hundred's place digit
    int last_two_digits = x % 100;        // Get the last two digits

    // Reversing the first two digits
    int reversed_first_two = second_digit * 10 + first_digit;

    // Forming the new number
    y = reversed_first_two * 100 + last_two_digits;

    printf("Result = %d\n", y);
    return 0;
}

