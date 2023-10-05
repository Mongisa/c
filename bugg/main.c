#include <stdio.h>
#include <stdlib.h>

int main() {

    int n,i,x;

    x=0;

    printf("inserire un numero positivo\n");
    scanf("%d",&n);
    
    printf("%d", n);

    if (n>0){

         i=0;
        do{
            /*if(x%2==0){
                printf("%d",x);
                x++;
                i++;
            }*/
            printf("PESCE");

        } while(i<n);
    } else {
        printf("il numero inserito è negativo");
    }






    return 0;
}

