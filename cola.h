//
// Created by ariel gonzalez on 9/26/17.
//

#ifndef COLA_COLA_H
#define COLA_COLA_H
#include "nodo.h"
#define TAM 3

typedef struct {
    t_nodo *fte, *fdo;
} t_cola;

void crear_cola(t_cola *pc);
int poner_en_cola(t_cola *pc, const t_dato *pd);
int sacar_de_cola(t_cola *pc, t_dato *pd);
int frente_cola(const t_cola * pc, t_dato *pd);
void vaciar_cola(t_cola *pc);
int cola_vacia(const t_cola *pc);
int cola_llena(const t_cola *pc);

#endif //COLA_COLA_H
