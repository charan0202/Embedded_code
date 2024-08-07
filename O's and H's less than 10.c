#include <stdio.h>

int main()
{
    int x ,y, one_digit, hundred_digit;
    printf("enter three digit number: ");
    scanf("%d",&x);
    
    one_digit = x%10;
    hundred_digit = x/100;
    
    if(one_digit + hundred_digit < 10){
        
        printf("success");
    }
    else{
        printf("failure");
    }

    return 0;
}