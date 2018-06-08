//
// Created by Ariel Gonzalez on 21/10/17.
//

#include "indice.h"

int comparar_dni(const t_reg_indice * dato1, const t_reg_indice * dato2){
    return (int)(dato1->dni - dato2->dni);
}

/**
 * Crea la lista y la cola
 */
void ind_crear (t_indice * indice){
    crear_lista(&indice->lista);
    crear_cola(&indice->cola);
    indice->eop = 1;
}

/**
 * inserta en la lista en orden según el dni
 * @return 1 (uno) si la operación fue exitosa y 0 (cero) en caso contrario.
 */
int ind_insertar (t_indice * indice, const t_reg_indice * reg_indice){
    return poner_ultimo_lista(&indice->lista, reg_indice);
}

/**
 * elimina el dni informado de la lista
 * @return 1 (uno) si la operación fue exitosa y 0 (cero) en caso contrario.
 */
int ind_eliminar (t_indice * indice, t_reg_indice * reg_indice){
    return eliminar_elemento(&indice->lista, reg_indice, comparar_dni);
}

/**
 * si el dni existe en la lista deja el registro en reg_ind
 * @return 1 (uno) si la operación fue exitosa y 0 (cero) en caso contrario.
 */
int ind_buscar (const t_indice * indice, t_reg_indice * reg_ind){
    return buscar_elemento(&indice->lista, reg_ind, comparar_dni);
}

/**
 * Carga la lista desde un archivo ordenado
 * @return 1 (uno) si la operación fue exitosa y 0 (cero) en caso contrario.
 */
void ind_cargar (t_indice * indice, char * path) {
    ///Esta función está hecha para cargar desde un .idx. Entonces,
    ///suponemos que ya esta ordenado, y deberiamos cargar la lista
    ///desde un archivo, lo mas eficiente posible, sin recorrer la
    ///lista varias veces.
    FILE * fidx;
    t_reg_indice regIndice;
    if(!(fidx=fopen(path,"rb"))) exit(1);
    fread(&regIndice,sizeof(t_reg_indice),1,fidx);
    while(!feof(fidx)){
        ind_insertar(indice,&regIndice);
        fread(&regIndice,sizeof(t_reg_indice),1,fidx);
    }
}

void texto_a_registro(char * registro_plain, t_reg_indice * registro, int nroRegistro){
    t_alumno alu;
    scanf(registro_plain,"%ld|\n",&alu.dni);
    registro->dni = alu.dni;
    registro->nro_reg = (unsigned int)nroRegistro;
}

/**
 * Graba un archivo con el contenido del índice
 * @return 1 (uno) si la operación fue exitosa y 0 (cero) en caso contrario.
 */
void action_write_text_file(const t_nodo * nodo, FILE * pf) {
    fprintf(pf, "%ld|%u\n",nodo->dato.dni, nodo->dato.nro_reg);
}

int ind_grabar (const t_indice* indice, const char* path) {
    FILE * pf = fopen(path, "wt");
    if(!pf) return 0;
    recorrer_lista(&indice->lista, pf, action_write_text_file);
    fclose(pf);
    return 1;
}

void ind_vaciar(t_indice* indice) {
    vaciar_cola(&indice->cola);
    vaciar_lista(&indice->lista);
}

void ind_recorrer(const t_indice * indice ,void(* accion)(t_reg_indice* reg_ind,void *param),void *param){
    t_lista * aux = &(indice->lista);
    while(*aux){
        accion(&(*aux)->dato,param);
        aux = &((*(aux))->psig);
    }
}

void action_fill_cola(const t_nodo * nodo, void * cola) {
    poner_en_cola(cola, &nodo->dato);
}

int ind_primero(t_indice* indice, t_reg_indice* reg_ind) {
    if(!indice || !indice->lista) return 0;
    // Reset
    t_lista * aux = &(indice->lista);
    indice->eop = 0;
    vaciar_cola(&indice->cola);

    // Devuelvo el primero
    (*reg_ind).dni = (indice->lista)->dato.dni;
    (*reg_ind).nro_reg = (indice->lista)->dato.nro_reg;

    // Cargo en la cola
    recorrer_lista(aux, &indice->cola, action_fill_cola);
    sacar_de_cola(&indice->cola, reg_ind);

    return 1;
}

int ind_siguiente(t_indice * indice, t_reg_indice * reg_ind) {
    if(!indice || !indice->lista) return 0;
    if(!sacar_de_cola(&indice->cola, reg_ind)) {
        indice->eop = 1;
    }
    return 1;
}


int ind_fin (const t_indice* indice) {
    return indice->eop;
}
