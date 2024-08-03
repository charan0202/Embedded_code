#include <stdio.h>

int main() {
    int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Subtract 5
    result = num - 5;

    // Extract the ten's digit
    int tens_digit = (result / 10) % 10;

    // Create an array of messages where the index corresponds to odd/even check
    const char *messages[] = {"even", "odd"};

    // Print the result based on the parity of the ten's digit
    printf("%s\n", messages[tens_digit % 2]);

    return 0;
}

