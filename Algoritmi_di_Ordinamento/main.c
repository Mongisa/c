/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 19 gennaio 2024, 12:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selection_sort(int*,int);
void insertion_sort(int*,int);
void bubble_sort(int*,int);
void merge_sort(int*,int,int*);
void merge1(int*,int,int*,int,int*);
void merge2(int*,int,int*,int,int*);
void quick_sort(int*,int);
int partition(int*,int);

void array_print(int*,int);
void swap(int*,int*);

int main(int argc, char** argv) {

    int vet[11] = {7,4,3,6,5,9,8,0,2,1};
    int temp[11];
    int n = 10;
    
    array_print(vet,n);
    printf("\n");
        
    //selection_sort(vet,n);
    //insertion_sort(vet,n);
    //bubble_sort(vet,n);
    //merge_sort(vet,n,temp);
    quick_sort(vet,n);
    
    array_print(vet,n);
    
    return (EXIT_SUCCESS);
}

/* SELECTION SORT */
void selection_sort(int* vet,int n) {
    for(int i=0;i<n;i++) {
        int imin = i;
        
        for(int k=i+1;k<n;k++) { //Cerco il minimo locale
            if(vet[k] < vet[imin])
                imin = k;
        }
        
        if(imin!=i) { //Posiziono il minimo trovato all'inizio
            int tmp = vet[i];
            vet[i] = vet[imin];
            vet[imin] = tmp;
        }
    }
}

/* INSERTION SORT */
void insertion_sort(int* vet,int n) {
    for(int i=1;i<n;i++) {
        int x = vet[i];
        int pos;
        for(pos=i;pos>0 && x < vet[pos-1];pos--);
        for(int k=i-1;k>=pos;k--) {
            vet[k+1] = vet[k]; 
        }
        vet[pos] = x;
    }
}

/* BUBBLE SORT */
void bubble_sort(int* vet,int n) {
    bool modified = true;
    
    for(int i=0;i<n-1 && modified;i++) {
        modified = false;
        for(int k=0;k<n-i-1;k++) {
            if(vet[k]>vet[k+1]) {
                swap(&vet[k+1],&vet[k]);
                modified = true;
            }
        }
    }
}

/* MERGE SORT */
void merge_sort(int a[],int n,int temp[]) {
    int m = n/2;
    if(n<2) return;
    
    merge_sort(a,m,temp);
    merge_sort(a+m,n-m,temp);
    merge2(a,m,a+m,n-m,temp);
    for(int i=0; i<n;i++)
        a[i]=temp[i];
}

void merge2(int a[],int n1,int b[],int n2,int temp[]) {
    int ia = 0,ib = 0;
    for(int i=0;i<n1+n2;i++) {
        if(ia<n1 && ib<n2) {
            if(a[ia] < b[ib]) {
                temp[i] = a[ia++];
            } else {
                temp[i] = b[ib++];
            }
        } else if(ia<n1) {
            temp[i] = a[ia++];
        } else {
            temp[i] = b[ib++];
        }
    }
    
}
void merge1(int a1[], int n1, int a2[], int n2, int dest[]) {
    int pos1=0, pos2=0, k=0;
    
    while (pos1<n1 && pos2<n2) {
        if (a2[pos2] < a1[pos1])
            dest[k++] = a2[pos2++];
        else
            dest[k++] = a1[pos1++];
    }

    while (pos1<n1)
        dest[k++] = a1[pos1++];

    while (pos2<n2)
        dest[k++] = a2[pos2++];
}

/* QUICK SORT */
void quick_sort(int a[], int n) {
    int k;
    if(n<2) return;
    k = partition(a, n);
    quick_sort(a, k);
    quick_sort(a+k+1, n-k-1);
}

int partition(int a[], int n) {
    int i, k=1;
    for(i=1; i<n; i++)
        if((a[i] < a[0]))
            swap(&a[i], &a[k++]);
    swap(&a[0], &a[k-1]);
    return k-1;
}

/* FUNZIONI DI UTILITA' */
void array_print(int* vet,int n) {
    for(int i=0;i<n;i++)
        printf("%d ",vet[i]);
    printf("\n");
}

void swap(int*a,int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}