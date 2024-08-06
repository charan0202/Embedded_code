#include <stdio.h>

int main()
{
    int number, result, hundreds_digit, ones_digit;
    
    // Get the three-digit number from the user
    printf("Enter a three-digit number: ");
    scanf("%d", &number);
    
    // Subtract 5 from the number
    result = number - 5;
    
    // Extract the hundred's and one's digits
    hundreds_digit = result / 100;  // Get the hundred's digit
    ones_digit = result % 10;       // Get the one's digit
    
    // Print the result if hundred's and one's digit are the same using the conditional operator
    printf("%s%d\n", (hundreds_digit == ones_digit) ? "Result: " : "", (hundreds_digit == ones_digit) ? result : 0);

    return 0;
}