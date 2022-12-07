#include <stdio.h>
#include <math.h>

int main() {
    int b,h,area,per;
    float diag;
 
    printf("Inserisci base e altezza del rettangolo: ");
    scanf("%d %d", &b, &h);
    
    per = 2*(b+h);
    area = b*h;
    diag = sqrt(b*b+h*h);
    
    printf("Perimetro: %d\n", per);
    printf("Area: %d\n", area);
    printf("Diagonale %.2lf\n", diag);
    
    return 0;
}