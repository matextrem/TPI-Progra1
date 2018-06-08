//
// Created by ariel gonzalez on 9/26/17.
//
#include "cola.h"
#include <stdlib.h>

void crear_cola(t_cola *pc) {
    pc->fte = NULL;
    pc->fdo = NULL;
}

int cola_vacia(const t_cola *pc) {
    return pc -> fte == NULL;
}

int cola_llena(const t_cola *pc) {
    t_nodo * nodo = malloc(sizeof(t_nodo));
    if(nodo == NULL) {
      return 1;
    }
    free(nodo);
    return 0;
}

void vaciar_cola(t_cola *pc) {
    while (pc -> fte != NULL) {
        t_nodo * aux = pc->fte;
        if((pc->fte)->psig) {
            pc->fte = (pc->fte)->psig;
        }
        free(aux);
    }
    pc->fdo = NULL;
}

int frente_cola(const t_cola * pc, t_dato *pd) {
    if (pc->fte == NULL) return 0;
    *pd = pc->fte->dato;
    return 1;
}

int poner_en_cola(t_cola *pc, const t_dato *pd) {
    t_nodo * nodo = (t_nodo*)malloc(sizeof(t_nodo));
    if(nodo == NULL) return 0;
    nodo->dato = *pd;
    nodo->psig = NULL;

    if(pc->fte == NULL) {
        pc->fte = nodo;
    } else {
        pc->fdo->psig = nodo;
    }
    pc->fdo = nodo;

    return 1;
}

int sacar_de_cola(t_cola *pc, t_dato *pd) {
    if(pc->fte == NULL) return 0;
    t_nodo * aux = pc->fte;
    *pd = pc->fte->dato;
    if(pc->fte == pc->fdo) {
        pc->fte = NULL;
        pc->fdo = NULL;
    } else {
        pc->fte = pc->fte->psig;
    }
    free(aux);
    return 1;
}








