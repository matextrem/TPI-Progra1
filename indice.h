//
// Created by Ariel Gonzalez on 21/10/17.
//

#ifndef PROGRA_TPI_INDICE_H
#define PROGRA_TPI_INDICE_H
#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "lista.h"
#include "fecha.h"

typedef struct {
    unsigned long dni;
    char AyN[40];
    t_fecha fechaNac;
    char sexo;
    t_fecha fechaIng;
    char carrera[4];
    int matAprob;
    t_fecha fechaAprobUltima;
    char estado;
    t_fecha fechaBaja;
}t_alumno;

typedef struct {
    t_cola cola;
    t_lista lista;
    int eop;
}t_indice;

void ind_crear (t_indice*);
int ind_insertar (t_indice*, const t_reg_indice*);
int ind_eliminar (t_indice*, t_reg_indice*);
int ind_buscar (const t_indice*, t_reg_indice* reg_ind);
void ind_cargar (t_indice*, char * path);
int ind_grabar (const t_indice*, const char* path);
void ind_vaciar(t_indice*);
int ind_primero(t_indice*, t_reg_indice* reg_ind);
int ind_siguiente(t_indice*, t_reg_indice*);
int ind_fin (const t_indice*);
void ind_recorrer(const t_indice * indice ,void(* accion)(t_reg_indice* reg_ind,void *param),void *param);
void texto_a_registro(char * registro_plain, t_reg_indice * registro, int nroRegistro);
#endif //PROGRA_TPI_INDICE_H
