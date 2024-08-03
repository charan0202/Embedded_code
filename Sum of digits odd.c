#include <stdio.h>

int main() {
    int num, result;
    printf("Enter a two-digit number: ");
    scanf("%d", &num);

    // Subtract 5
    result = num - 5;
    
    // Extract the digits
    int tens_digit = result / 10;
    int ones_digit = result % 10;
    
    // Compute the sum of the digits
    int sum_digits = tens_digit + ones_digit;

    // Create an array of messages where index 0 is an empty string and index 1 is the result
    const char *messages[] = {"", "%d\n"};

    // Print the result based on the parity of the sum of the digits
    printf(messages[sum_digits % 2], result);

    return 0;
}


