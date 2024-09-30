#include <stdio.h>
#define IN  1
#define OUT 0
//Write a program that prints its input one word per line

int main(){
     
     int c , i , nspace , nothers;
     int ndigit[10];
     
     for(i =0; i<=10; i++){
          ndigit[i]= 0;
     }
     while(c = getchar() != EOF){
          if(c>='0' && c<= '9'){
               ++ndigit[c-'0'];
          }else if(c =='\n' || c =='\t' || c == ' '){
               ++nspace;
          }else{
               ++nothers;
          }
     }
     printf("%d %d", nspace, nothers);
     
}
     
     