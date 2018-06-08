//
// Created by Ariel Gonzalez on 10/14/17.
//
#ifndef PROGRA_TPI_FECHA_H
#define PROGRA_TPI_FECHA_H

typedef struct {
    int a, d, m;
} t_fecha;

int esAnioBisiesto(const t_fecha * fecha);
int cantidadDeDias(const t_fecha * fecha);
int esFechaValida(const t_fecha * fecha);
void sumarAniosFecha(t_fecha * fechaNac, int anios);
int compararFecha(const t_fecha * fecha1, const t_fecha * fecha2);

/**
 * Determina la cantidad de dias desde el comienzo del anio
 * @return nro de dias.
 */
int dias_juliano(const t_fecha * fecha);

/**
 * Retorna la diferencia de dias. Si la fecha1 es mayor que la fecha2 devuelve numero > 0
 * si la fecha2 es mayor que la fecha1, devuelve numero < 0
 * @return 1 (uno) si la operación fue exitosa y 0 (cero) en caso contrario.
 */
int diferencia_dias(const t_fecha * fecha1, const t_fecha * fecha2);


#endif //PROGRA_TPI_FECHA_H
