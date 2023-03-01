#include <stdio.h>
void main() {
    int a,b,r;

    printf("Enter number a : ");
    scanf("%d", &a);
    
    printf("\nEnter number b : ");
    scanf("%d", &b);

    if(a==0) printf(" %d is GCD", b);
    
    else if(b==0) printf(" %d is GCD", a);

   else{
   	
    while(b!=0) {
        r=a%b;
        a=b;
        b=r;
    }
    printf("%d",a);
}

    
}

