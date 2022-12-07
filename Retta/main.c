#include <stdio.h>

int main() {
    float x1,y1,x2,y2,m,p;
    
    printf("Inserisci ascissa e ordinata del 1 punto: ");
    scanf("%f %f", &x1, &y1);
    
    printf("Inserisci ascissa e ordinata del 2 punto: ");
    scanf("%f %f", &x2, &y2);
    
    m= (y2-y1)/(x2-x1);
    p= y1 - m*x1;
    
    printf("y=%.2lfx + %.2lf", m, p);
    
    return 0;
}