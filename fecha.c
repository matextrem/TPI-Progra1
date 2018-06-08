//
// Created by Ariel Gonzalez on 10/14/17.
//
#include "fecha.h"
#include "validations.h"
#include <stdio.h>

int esAnioBisiesto(const t_fecha * fecha) {
    return (fecha->a % 4 == 0 && fecha->a % 100 != 0) || fecha->a % 400 == 0;
}

int dias_juliano(const t_fecha * fecha){
    int total = 0, mes;
    for(mes = 0; mes < fecha->m - 1; mes++){
        total += cantidadDeDias(fecha);
    }
    return total + fecha->d;
}

int diferencia_dias(const t_fecha * fecha1, const t_fecha * fecha2){
    int cant_anios1 = fecha1->a - 1601;
    int cant_anios2 = fecha2->a - 1601;
    int cant_dias1 = cant_anios1 * 365 + cant_anios1/4 - cant_anios1/100 + cant_anios1/400 + dias_juliano(fecha1);
    int cant_dias2 = cant_anios2 * 365 + cant_anios2/4 - cant_anios2/100 + cant_anios2/400 + dias_juliano(fecha2);
    return cant_dias1 - cant_dias2;
}

int cantidadDeDias(const t_fecha * fecha) {
    int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (dias[(fecha->m) -1] + esAnioBisiesto(fecha));
}

int esFechaValida(const t_fecha * fecha) {
    if(fecha->a >= 1601) {
        if(fecha->m <= 12 && fecha->m >= 1) {
            if(fecha->d >= 1 && fecha->d <= cantidadDeDias(fecha)) {
                return 1;
            }
        }
    }
    return 0;
}

// Para el caso de la fecha 29-02 de biciesto, se corrige el dia a 28
void sumarAniosFecha(t_fecha * fecha, int anios){
    fecha->a = fecha->a + anios;
    if(esAnioBisiesto(fecha) && fecha->m == 2 && fecha->d == 29)
        fecha->d = 28;
}

int compararFecha(const t_fecha * fecha1, const t_fecha * fecha2) {
    return diferencia_dias(fecha1, fecha2);
}

