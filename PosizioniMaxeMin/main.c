#include <stdio.h>
#define SIZE 150

int main() {
    int vett[SIZE];
    int n, arrayLength, maxPos, maxVal, minPos, minVal;
    
    arrayLength = 0;
    
    do {
        printf("Inserisci un numero (-999 per terminare)");
        scanf("%d", &n);
        
        if(n!=-999) {
            vett[arrayLength] = n;
            arrayLength++;
        }
    } while(n != -999);
   
    minPos = 0;
    maxPos = 0;
    
    minVal = vett[minPos];
    maxVal = vett[maxPos];
    
    for(int i=0; i<arrayLength; i++) {
        if(vett[i] > maxVal) {
            maxPos = i;
            maxVal = vett[i];
        } else if(vett[i] < minVal) {
            minPos = i;
            minVal = vett[i];
        }
    }
    
    printf("Valore minimo: %d \nPosizione: %d\n", minVal, minPos);
    printf("Valore max: %d \nPosizione: %d\n", maxVal, maxPos);
    
    return 0;
}