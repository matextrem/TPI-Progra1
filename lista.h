//
// Created by ariel gonzalez on 10/7/17.
//

#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H
#include "nodo.h"

typedef t_nodo * t_lista;

void crear_lista(t_lista *pp);
void vaciar_lista(t_lista *pl);
void mostrar_lista(t_lista *pl);
int contar_elementos(t_lista *pl);
int poner_ultimo_lista(t_lista *pp, const t_dato * pd);
int poner_en_posicion(t_lista *pp, t_dato *pd, int pos);
int poner_primero_lista(t_lista *pp, t_dato *pd);
int poner_ordenado(t_lista *pl,const t_dato *pd, int(*cmp)(const t_dato*, const t_dato*));
int eliminar_elemento(t_lista *pl, t_dato * pd, int(*cmp)(const t_dato*, const t_dato*));
int sacar_ultimo(t_lista *pl, t_dato * pd);
int sacar_posicion(t_lista *pl, int pos, t_dato *pd);
int buscar_elemento(t_lista *pl, t_dato * pd, int(*cmp)(const t_dato*, const t_dato*));
void recorrer_lista(t_lista *pl, void * arg, void(*action)(const t_nodo*, void * arg2));


void ordenar_lista(t_lista *pl, int(*cmp)(const t_dato*, const t_dato*));
t_nodo ** buscar_menor_lista(t_lista *pl, int (*cmp)(const t_dato*, const t_dato*));
int eliminar_duplicados(t_lista *pl);
int eliminar_no_duplicados(t_lista *pl);


#endif //LISTA_LISTA_H
