//
// Created by Ariel Gonzalez on 10/14/17.
//

#ifndef PROGRA_TPI_VALIDATIONS_H
#define PROGRA_TPI_VALIDATIONS_H

#include "fecha.h"

int validarDni(const unsigned long * dni);
int validarNombre(const char * AyN);
int validarFechaNac(const t_fecha * fechaNac, const t_fecha * fechaProce);
int validarSexo(char * sexo);
int validarFechaIng(const t_fecha * fechaIng, const t_fecha * fechaNac, const t_fecha * fechaProces);
int validarCarrera(char * carrera);
int validarMateriasAprobadas(const int * matAprob);
int validarFechaUltimaAprob(const t_fecha * fechaAprobUltima, const t_fecha * fechaIng, const t_fecha * fechaProces);
int validarEstado(const char * estado );
int validarFechaBaja(const t_fecha * fechaBaja);

#endif //PROGRA_TPI_VALIDATIONS_H
