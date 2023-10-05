#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int array_leggi(int vet[], int dim_fis);
int rip_max (int p[], int n, int* v);
void stampa_una_volta (int vet[], int n);

int main()
{
    int vet[MAX];
    int riemp1, val, quant;
    int dist=0;

    riemp1 = array_leggi(vet, MAX);
    printf("La dimensione del vettore vet è: %d\n", riemp1);

    val = rip_max(vet, riemp1, &quant);   
      printf("Il primo numero intero che compaie più volte per %d volte, è: %d\n", quant, val);

    printf ("Gli elementi che appaiono una volta nell'array sono:\n");
    stampa_una_volta(vet, riemp1);

return 0;

}

/* Il sottoprogramma legge dallo standard input (ossia da tastiera) una sequenza di numeri
   interi diversi da 0; i valori letti vengono progressivamente memorizzati nel vettore 
   passato tramite il parametro vet; l'acquisizione si interrompe quando viene raggiunta
   la dimensione fisica di vet (passata tramite il parametro dim_fis) oppure quando l'utente
   digita il valore 0. Il sottoprogramma restituisce la dimensione logica di vet.
*/
int array_leggi(int vet[], int dim_fis){
    int curr, riemp=0;
    
    printf("Inserisci un valore (inserisci 0 per terminare): ");
    scanf("%d", &curr);
    
    while(curr != 0 && riemp < dim_fis) {
        vet[riemp] = curr;
        
        printf("Inserisci un valore (inserisci 0 per terminare): ");
        scanf("%d", &curr);
        
        riemp++;
    }
    
    return riemp;
}


/* Il sottoprogramma dato in input un array di interi, 
stampa il numero che compare più volte all’interno dell’array, 
qualora ci siano più numeri che compaiano lo stesso numero di volte 
restituisce in output quello che compare per primo.
*/
int rip_max (int p[], int n, int* v){
    int nacc=1, sel, i,j, val;
    
    *v=0;
    sel=p[0];
    
    for(i=0; i<n; i++) {
        val = p[i];
        nacc = 1;
        for(j=i+1; j<n;j++) {
            if(val == p[j]) {
                nacc++;
            }
        }
        
        if(nacc > *v) {
            sel = p[i];
            *v = nacc;
        }
    }
    
    return sel;

}

/* Il sottoprogramma dato in input un array di interi,
stampa solo i numeri che appaiono nell’array 
una volta soltanto.
*/
void stampa_una_volta(int p[], int n){
    int i,j, nacc, val;
    
    for(i=0; i<n; i++) {
        val = p[i];
        nacc = 0;
        for(j=0; j<n; j++) {
            if(val == p[j]) {
                nacc++;
            }
        }
        
        if(nacc == 1) {
            printf("%d compare una volta \n", val);
        }
    }
}