#include <stdio.h>

int main() {
    
    int mese, anno, giorni;
    
    printf("Inserisci mese e anno \n");
    scanf("%d %d", &mese, &anno);
    
    if(mese > 12) {
        printf("Il mese inserito non è corretto!");
        return 0;
    } 
    
    switch(mese) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            giorni = 31;
            break;
        case 2:
            if(anno % 4 == 0 && anno % 100 != 0 || anno%400 == 0) {
                giorni = 29;
            } else {
                giorni = 28;
            }
            break;
        case 11: case 4: case 6: case 9:
            giorni = 30;
            break;
    };
    
    printf("Giorni %d", giorni);
    
    return 0;
}