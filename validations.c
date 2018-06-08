//
// Created by Ariel Gonzalez on 10/14/17.
// Power by Pablo Del Valle B-)
//
#include "validations.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tp_utils.h"

// Validación formal y < fecha de proceso - 10 años
int validarFechaNac(const t_fecha * fechaNac, const t_fecha * fechaProce) {
    t_fecha aux = *fechaNac;
    sumarAniosFecha(&aux, 10);
    return (esFechaValida(fechaNac) && compararFecha(fechaProce, &aux) > 0);
}

int validarSexo(char * sexo) {
    *sexo = toupper(*sexo);
    return (*sexo == 'M' || *sexo == 'F');
}

int validarMateriasAprobadas(const int * matAprob) {
    return *matAprob >= 0;
}

// > fecha-ingreso y <= fecha de proceso
int validarFechaUltimaAprob(const t_fecha * fechaAprobUltima, const t_fecha * fechaIng, const t_fecha * fechaProces) {
    return (compararFecha(fechaAprobUltima, fechaProces) <= 0) && (compararFecha(fechaAprobUltima, fechaIng));
}

// <= fecha de proceso y > fecha de nacimiento
int validarFechaIng(const t_fecha * fechaIng, const t_fecha * fechaNac, const t_fecha * fechaProces) {
    return (compararFecha(fechaProces, fechaIng) >= 0) && (compararFecha(fechaIng, fechaNac) > 0);
}

int validarDni(const unsigned long * dni) {
    return *dni > 10000 && *dni < 100000000;
}

int validarCarrera(char * carrera){
    static const char * materias[] = {"INF","ELE","IND","ECO","DER","ADM","MED","EDF","FIL"};
    int i=0,inArray = 0;
    char * first = carrera;
    while(*carrera){
        *carrera = toupper(*carrera);
        carrera++;
    }
    while(!inArray && materias[i]){
        if(strcmp(first,materias[i]) == 0) inArray = 1;
        i++;
    }

    return inArray;
}

int validarEstado(const char * estado ){
    return *estado == 'R';
}

int validarFechaBaja(const t_fecha * fechaBaja){
    t_fecha fecha;
    fecha.d = 31;
    fecha.m = 12;
    fecha.a = 9999;
    return (compararFecha(fechaBaja, &fecha) != 0);
}
