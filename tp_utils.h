#ifndef TP_UTILS_H_INCLUDED
#define TP_UTILS_H_INCLUDED

#include <stdio.h>
#include <time.h>
#include "indice.h"
#include "validations.h"
#include "lista.h"


void normalizarApyN(char *);
void ingresar_datos(t_alumno * , t_fecha *, int isMacOSX);
void crearArchivoAlumnos(int isMacOSX,t_fecha * fechaProc);
void mostrarMenu(void);
void setAlumnoGenerico(t_alumno *);
void clean_stdin(int isMacOSX);
void texto_a_binario(char * path, const t_fecha * fechaProc,t_alumno * alu,t_indice * indice);
int texto_a_alumno(char * reg, t_alumno * alu,FILE * fpError,const t_fecha * fechaProc);
void generarMensajeError(int i, char * aux);
int isMacOS(void);
void listBregister(char * path);
void mostrarArchivoAlumnos(char *path);
void mostrarArchivoBin(char * path);
void mostrarNoBajas(char * path);
void imprimir(t_reg_indice* reg_ind);
void indexToMemory(FILE*,t_indice*);
void grabarArchivoidx(t_reg_indice *  dato_indice,void *fidx);
void action_write_idx(const t_nodo * nodo, FILE * fpIdx);


#endif // TP_UTILS_H_INCLUDED
