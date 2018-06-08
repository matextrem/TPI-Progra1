//
// Created by ariel gonzalez on 10/7/17.
//
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "nodo.h"
#define DEFAULT_VALUE 10;
void crear_lista(t_lista *pl) {
    *pl = NULL;
}

int poner_ultimo_lista(t_lista *pl, const t_dato *pd) {
    while (*pl) {
        pl = &(*pl)->psig;
    }
    *pl = (t_nodo *) malloc(sizeof(t_nodo));
    if (!*pl) return 0;
    (*pl)->dato = *pd;
    (*pl)->psig = NULL;
    return 1;
}

int poner_en_posicion(t_lista *pl, t_dato *pd, int pos) {
    t_nodo * pnue;
    while(*pl && pos>1) {
        pl = &(*pl)->psig;
        pos--;
    }
    pnue = (t_nodo *)malloc(sizeof(t_nodo));
    if(!pnue) return 0;
    pnue->dato = *pd;
    pnue->psig = *pl;
    *pl = pnue;
    return 1;
}

int poner_ordenado(t_lista *pl, const t_dato *pd, int(*cmp)(const t_dato*, const t_dato*)) {
    int compare = DEFAULT_VALUE;
    while(*pl && (compare = cmp(pd, &(*pl)->dato)) > 0) {
        pl = &(*pl)->psig;
    }
    if (!compare) return 0;
    t_nodo * aux = (t_nodo *)malloc(sizeof(t_nodo));
    aux->dato = *pd;
    aux->psig = *pl;
    *pl = aux;
    return 1;
}

void mostrar_lista(t_lista *pl){
    printf("[");
    while (*pl) {
        printf("%d, ",(*pl)->dato);
        *pl = (*pl)->psig;
    }
    printf("]\n");
}

void recorrer_lista(t_lista *pl, void * arg, void(*action)(const t_nodo*, void *)) {
    t_nodo * aux = *pl;
    while(aux) {
        action(aux, arg);
        aux = aux->psig;
    }
}

int contar_elementos(t_lista *pl) {
    int cant = 0;
    while(*pl) {
        pl = &(*pl)->psig;
        cant++;
    }
    return cant;
}

int buscar_elemento(t_lista *pl, t_dato * pd, int(*cmp)(const t_dato*, const t_dato*)) {
    int contador;
    while(*pl && (contador = cmp(pd, &(*pl)->dato)) != 0) {
        pl = &(*pl)->psig;
    }
    if(contador != 0) return 0;
    *pd = (*pl)->dato;
    return 1;
}

int eliminar_elemento(t_lista *pl, t_dato * pd, int(*cmp)(const t_dato*, const t_dato*)) {
    t_nodo * aux;
    int contador;
    while(*pl && (contador = cmp(pd, &(*pl)->dato)) != 0) {
        pl = &(*pl)->psig;
    }
    aux = (t_nodo*) malloc(sizeof(t_nodo));
    if(!aux || contador != 0) return 0;
    aux = *pl;
    *pl = (*pl)->psig;
    free(aux);
    return 1;
}

int sacar_ultimo(t_lista *pl, t_dato * pd) {
    if(!*pl) return 0;
    while(*pl && (*pl)->psig) {
        pl = &(*pl)->psig;
    }
    *pd = (*pl)->dato;
    free(*pl);
    *pl = NULL;
    return 1;
}

int sacar_posicion(t_lista *pl, int pos, t_dato *pd) {
    if(!*pl) return 0;
    t_nodo * aux;

    while(*pl && pos > 1) {
        pl = &(*pl)->psig;
        pos--;
    }
    aux = (t_nodo*)malloc(sizeof(t_nodo));
    if (pos != 1 || !aux) return 0;
    *pd = (*pl)->dato;
    aux = *pl;
    *pl = (*pl)->psig;
    free(aux);

    return 1;
}

void vaciar_lista(t_lista *pl) {
    t_nodo * aux;
    while(*pl) {
        aux = (t_nodo *)malloc(sizeof(t_nodo));
        if (aux) {
            aux = *pl;
            *pl = (*pl)->psig;
            free(aux);
        }
    }
}

//TODO: Terminar ejercico... falta intercambio, buscar menor funca.
void ordenar_lista(t_lista *pl, int (*cmp)(const t_dato *, const t_dato *)) {
    /*
    t_nodo ** menor;
    while(*pl && (*pl)->psig) {
        menor = buscar_menor_lista(pl, cmp);
        //si no soy yo, entonces intercambio
        if(menor != pl) {

            aux->psig = (*pl)->psig;
            (*pl)->psig = aux->psig;
        }
        //Avanzo
        pl = &(*pl)->psig;
    }
     */
}

t_nodo ** buscar_menor_lista(t_lista *pl, int (*cmp)(const t_dato*, const t_dato*)) {
    t_nodo ** nodoMenor = pl;
    pl = &(*pl)->psig;
    while(*pl) {
        if(cmp(&(*pl)->dato, &(*nodoMenor)->dato) < 0) {
            nodoMenor = pl;
        }
        pl = &(*pl)->psig;
    }

    return nodoMenor;
}

void intercambio_nodos(t_nodo ** n1, t_nodo ** n2) {
    /*
    t_nodo *aux;
    if((*n1)->psig == *n2) {
        aux = *n2;
        *n2 = aux->psig;
        aux->psig = *n1;
        *n1 = aux;
    } else {
        intercambio(&(*n1)->psig, &(*n2)->psig, sizeof(t_nodo *));
        intercambio(n1, n2, sizeof(t_nodo *));
    }
     */
}
