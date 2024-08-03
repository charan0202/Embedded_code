#include <stdio.h>

int main() {
    int x, y;
    printf("Enter Number: ");
    scanf("%d", &x);

    // Extracting the digits
    int first_digit = x%10;           // Get the thousand's place digit
    int second_digit = (x /10) % 10;    // Get the hundred's place digit
    int last_two_digits = x / 100;        // Get the last two digits

    // Reversing the first two digits
    int reversed_first_two = first_digit * 10 + second_digit;

    // Forming the new number
    y = last_two_digits * 100 + reversed_first_two;

    printf("Result = %d\n", y);
    return 0;
}

