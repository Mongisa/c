#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Definizione della struttura dati */
#define CAPACITY 100

typedef char TInfo;

struct SStack {
    int n;
    TInfo a[CAPACITY];
};
typedef struct SStack TStack;

/* Crea uno stack
 */
TStack stack_create(void);

/* Distrugge uno stack
 */
void stack_destroy(TStack *stack);
/* Inserisce un elemento
 * PRE:
 * lo stack non e’ pieno
 */
void stack_push(TStack *stack, TInfo x);

/* Preleva un elemento
 * PRE:
 * lo stack non e’ vuoto
 */
TInfo stack_pop(TStack *stack);

/* Elemento in cima
 * PRE:
 * lo stack non e’ vuoto
 */
TInfo stack_top(TStack *stack);

/* Verifica se lo stack e’ vuoto
 */
bool stack_is_empty(TStack *stack);

/* Verifica se lo stack e’ pieno
 */
bool stack_is_full(TStack *stack);