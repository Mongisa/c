#include <stdio.h>
#include <math.h>

int main() {
    float dt = 0.5;
    
    int vel_i, i; 
    float x, y, t, angolo_lancio;
    
    printf("Inserisci angolo di lancio (in gradi)");
    scanf("%f", &angolo_lancio);
    
    printf("Inserisci velocità iniziale");
    scanf("%d", &vel_i);
    
    x = 0;
    y = 0;
    i = 1;
    
    angolo_lancio = M_PI*angolo_lancio/180;
    
    do {
        t = i * dt;
        
        x = round(vel_i*cos(angolo_lancio)* t);
        y = vel_i*sin(angolo_lancio)* t - (1/2)*9.81*pow(t, 2);
        
        printf("x[%d]: %f | ", i, x);
        printf("y[%d]: %f \n", i, y);
        
        i++;
    } while (x != 0 && y != 0);
        
    return 0;
}