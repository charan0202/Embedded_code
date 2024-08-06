#include <stdio.h>

int main()
{
    int x;
    printf("enter two digit number :");
    scanf("%d",&x);
    
    int ten_digit = x/10;
    int hundred_digit = x%10;
    
    if(ten_digit + hundred_digit ==10){
        
        printf("result %d ", x);
    }
    else{
        printf("invalid");
        
    }
}

