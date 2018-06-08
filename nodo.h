//
// Created by ariel gonzalez on 21/10/17.
//

#ifndef PROGRA_TPI_NODO_H
#define PROGRA_TPI_NODO_H

typedef struct {
    unsigned long dni;
    unsigned nro_reg;
} t_reg_indice;

typedef t_reg_indice t_dato;

typedef struct s_nodo{
    t_dato dato;
    struct s_nodo * psig;
}t_nodo;

#endif //PROGRA_TPI_NODO_H
