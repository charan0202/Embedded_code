#include <stdio.h>

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    // Subtract 5 from the number
    x = x - 5;

    // Check if the number is odd by using bitwise AND with 1
    // The result of x & 1 is 1 if x is odd, 0 if x is even.
    // Multiply x by the result of (x & 1) to print only if it is odd
    printf("%d", x * (x & 1));

    return 0;
}

