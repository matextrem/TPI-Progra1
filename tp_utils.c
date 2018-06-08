
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tp_utils.h"
#include "fecha.h"
#include "nodo.h"
#include "indice.h"

// Sorry guys...
int isMacOS() {
    int isMacOS = 0;
    printf("Estas corriendo sobre MAC OS SUPER PRO? (1 / 0): ");
    scanf("%d", &isMacOS);
    return isMacOS;
}

void normalizarApyN(char *cad){
    char cadNorm[40];
    char *aux = cad;
    int band = 0,i = 0, bandEsp = 0, bandComa = 0;
    while(*aux){
        if(*aux == ',') bandComa = 1;
        aux++;
    }
    aux = cad;
    while(*aux){
        if(*aux != ' ' && *aux != ','){
            if(!band){
                cadNorm[i] = toupper(*aux);
                band = 1;
            }
            else cadNorm[i] = tolower(*aux);
            i++;
        }
        else{
                if(!bandComa && !bandEsp){
                    cadNorm[i] = ',';
                    i++;
                    bandEsp = 1;
                }
                cadNorm[i] = *aux;
                i++;
                band = 0;
        }
        aux++;
    }
    cadNorm[i] = '\0';
    i=0;
    while(cadNorm[i]) {
        *cad = cadNorm[i];
        cad++;
        i++;
    }
}

void ingresar_datos(t_alumno * alu, t_fecha * fechaProce, int isMacOSX) {
    char apellido[20];
    char nombre[20];

    while(!esFechaValida(fechaProce)){
        printf("Error. Ingrese la fecha actual d/m/aaaa: ");
        scanf("%d/%d/%d", &fechaProce->d, &fechaProce->m, &fechaProce->a);
    }

    printf("Ingrese DNI del alumno: ");
    clean_stdin(isMacOSX);
    scanf("%lu",&alu->dni);
    while(!validarDni(&alu->dni)){
        printf("Error. Ingrese DNI del alumno: ");
        scanf("%lu",&alu->dni);
    }
    printf("Ingrese apellido y nombre: ");
    clean_stdin(isMacOSX);
    gets(alu->AyN);
    normalizarApyN(alu->AyN);

    printf("Ingrese la fecha de nacimiento d/m/aaaa: ");
    scanf("%d/%d/%d",&alu->fechaNac.d,&alu->fechaNac.m,&alu->fechaNac.a);
    while(!validarFechaNac(&alu->fechaNac, fechaProce)){
        printf("Error.Ingrese la fecha de nacimiento d/m/aaaa: ");
        clean_stdin(isMacOSX);
        scanf("%d/%d/%d",&alu->fechaNac.d,&alu->fechaNac.m,&alu->fechaNac.a);
    }
    printf("Ingrese sexo: ");
    clean_stdin(isMacOSX);
    scanf("%c",&alu->sexo);
    while(!validarSexo(&alu->sexo)){
        printf("Error. Ingrese sexo: ");
        clean_stdin(isMacOSX);
        scanf("%c",&alu->sexo);
    }

    printf("Ingresar fecha de ingreso d/m/aaaa: ");
    clean_stdin(isMacOSX);
    scanf("%d/%d/%d",&alu->fechaIng.d,&alu->fechaIng.m,&alu->fechaIng.a);
    while(!validarFechaIng(&alu->fechaIng, &alu->fechaNac, fechaProce)) {
        printf("Error.Ingresar fecha de ingreso d/m/aaaa: ");
        clean_stdin(isMacOSX);
        scanf("%d/%d/%d",&alu->fechaIng.d,&alu->fechaIng.m,&alu->fechaIng.a);
    }

    printf("Ingresar carrera: ");
    clean_stdin(isMacOSX);
    gets(alu->carrera);
    while(!validarCarrera(alu->carrera)) {
        printf("Error. Ingresar carrera: ");
        clean_stdin(isMacOSX);
        scanf("%s", alu->carrera);
    }

    printf("Ingrese la cantidad de materias aprobadas: ");
    scanf("%d",&alu->matAprob);
    while(!validarMateriasAprobadas(&alu->matAprob)) {
        printf("Error.Ingrese la cantidad de materias aprobadas: ");
        scanf("%d",&alu->matAprob);
    }

    printf("Ingresar fecha de aprobacion de ultima materia d/m/aaaa: ");
    scanf("%d/%d/%d",&alu->fechaAprobUltima.d,&alu->fechaAprobUltima.m,&alu->fechaAprobUltima.a);
    while(!validarFechaUltimaAprob(&alu->fechaAprobUltima, &alu->fechaIng, fechaProce)) {
        printf("Error.Ingresar fecha de aprobacion de ultima materia d/m/aaaa: ");
        scanf("%d/%d/%d",&alu->fechaAprobUltima.d,&alu->fechaAprobUltima.m,&alu->fechaAprobUltima.a);
    }

    alu->estado = 'R';
    alu->fechaBaja.d = 31;
    alu->fechaBaja.m = 12;
    alu->fechaBaja.a = 9999;

}
void crearArchivoAlumnos(int isMacOSX,t_fecha * fechaProc){
    FILE * pfAlumnos;
    t_alumno alu;
    char respuesta = 'S';
    if(!(pfAlumnos = fopen("alumnos.txt","wt"))){
        printf("NO SE PUDO ABRIR EL ARCHIVO.");
        exit(1);
    }
    while(toupper(respuesta) == 'S'){
        //setAlumnoGenerico(&alu);
        ingresar_datos(&alu,fechaProc, isMacOSX);
        fprintf(pfAlumnos,"%lu|%s|%d/%d/%d|%c|%d/%d/%d|%s|%d|%d/%d/%d|%c|%d/%d/%d\n",
                           alu.dni, alu.AyN, alu.fechaNac.d, alu.fechaNac.m, alu.fechaNac.a, alu.sexo,
                           alu.fechaIng.d, alu.fechaIng.m, alu.fechaIng.a, alu.carrera, alu.matAprob,
                           alu.fechaAprobUltima.d,alu.fechaAprobUltima.m,alu.fechaAprobUltima.a,alu.estado,
                           alu.fechaBaja.d,alu.fechaBaja.m,alu.fechaBaja.a);
        printf("Desea seguir ingresando? (S / N): ");
        clean_stdin(isMacOSX);
        scanf("%c",&respuesta);
    }
    fclose(pfAlumnos);
}
void setAlumnoGenerico(t_alumno *alu){
    alu->dni = 20000;
    strcpy(alu->AyN,"Riquelme, Juan Roman");
    alu->fechaNac.d = 24;
    alu->fechaNac.m = 6;
    alu->fechaNac.a = 1978;
    alu->sexo = 'M';
    alu->fechaIng.d = 1;
    alu->fechaIng.m = 4;
    alu->fechaIng.a = 1990;
    strcpy(alu->carrera,"INF");
    alu->matAprob = 37;
    alu->fechaAprobUltima.d = 6;
    alu->fechaAprobUltima.m = 7;
    alu->fechaAprobUltima.a = 2017;
    alu->estado = 'R';
    alu->fechaBaja.d = 31;
    alu->fechaBaja.m = 12;
    alu->fechaBaja.a = 1999;
}

void clean_stdin(int isMacOSX) {
    if(isMacOSX) {
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
    } else {
        fflush(stdin);
    }
}

void action_write_idx(const t_nodo * nodo, FILE * fpIdx) {
    fwrite(&nodo->dato,sizeof(t_reg_indice),1,fpIdx);
}

void texto_a_binario(char * path, const t_fecha * fechaProc,t_alumno * alu,t_indice * indice){
    FILE *pfTxt,*pfBin,*fpIdx,*fpError;
    char reg[100];
    t_reg_indice reg_indice;
    unsigned int registro = 1;
    ind_crear(indice);
    if(!(pfTxt=fopen(path, "rt"))) {
        printf("No se pudo leer archivo Txt.");
        exit(1);
    } else if (!(pfBin = fopen("AlumnosBin.dat","wb"))) {
        printf("No se pudo leer archivo AlumnosBin.dat.");
        exit(2);
    } else if (!(fpError = fopen("error.txt","wt"))) {
        printf("No se pudo leer archivo error.txt.");
        exit(3);
    } else if (!(fpIdx = fopen("AlumnosBin.idx","wb"))) {
        printf("No se pudo leer archivo AlumnosBin.idx.");
        exit(4);
    }

    while(fgets(reg, sizeof(reg),pfTxt)){
        if(!strchr(reg,'\n')){
            printf("Registro Invalido");
            exit(2);
        }
        if(texto_a_alumno(reg,alu,fpError,fechaProc)){
            fwrite(alu,sizeof(t_alumno),1,pfBin);
            reg_indice.dni = alu->dni;
            reg_indice.nro_reg = registro;
            ind_insertar(indice, &reg_indice);
            registro++;
        }
    }
    // ind_grabar trabaja con un TXT y en este caso queremos hacerlo con un IDX.
    // O bien la hacemos genérica, o bien...
    recorrer_lista(&indice->lista, fpIdx, action_write_idx);
    fclose(pfTxt);
    fclose(pfBin);
    fclose(fpError);
    fclose(fpIdx);
}

int texto_a_alumno(char * reg, t_alumno * alu,FILE * fpError, const t_fecha * fechaProc){
    char cad[200],aux[50];
    int errors[9],i,hayError=0;

    sscanf(reg,"%lu|%[^|\n]|%d/%d/%d|%c|%d/%d/%d|%[^|\n]|%d|%d/%d/%d|%c|%d/%d/%d",&alu->dni,alu->AyN,&alu->fechaNac.d,&alu->fechaNac.m,
                    &alu->fechaNac.a,&alu->sexo,&alu->fechaIng.d,&alu->fechaIng.m,&alu->fechaIng.a,alu->carrera,&alu->matAprob,
                        &alu->fechaAprobUltima.d,&alu->fechaAprobUltima.m,&alu->fechaAprobUltima.a,&alu->estado,
                            &alu->fechaBaja.d,&alu->fechaBaja.m,&alu->fechaBaja.a);


    errors[0] = validarDni(&alu->dni);
    errors[1] = validarFechaNac(&alu->fechaNac,fechaProc);
    errors[2] = validarSexo(&alu->sexo);
    errors[3] = validarFechaIng(&alu->fechaIng,&alu->fechaNac,fechaProc);
    errors[4] = validarCarrera(alu->carrera);
    errors[5] = validarMateriasAprobadas(&alu->matAprob);
    errors[6] = validarFechaUltimaAprob(&alu->fechaAprobUltima,&alu->fechaIng,fechaProc);
    errors[7] = validarEstado(&alu->estado);
    errors[8] = validarFechaBaja(&alu->fechaBaja);
    for(i=0;i<7;i++){
        if(!errors[i]){
            hayError = 1;
            generarMensajeError(i,aux);
            strcat(cad,aux);
        }
    }

    if(hayError)
        //Escribo archivo errores
        fprintf(fpError,"%lu|%s|%d/%d/%d|%c|%d/%d/%d|%s|%d|%d/%d/%d|%c|%d/%d/%d|%s\n",alu->dni,alu->AyN,alu->fechaNac.d,alu->fechaNac.m,alu->fechaNac.a,alu->sexo,alu->fechaIng.d,alu->fechaIng.m,alu->fechaIng.a,alu->carrera,alu->matAprob,alu->fechaAprobUltima.d,alu->fechaAprobUltima.m,alu->fechaAprobUltima.a,alu->estado,alu->fechaBaja.d,alu->fechaBaja.m,alu->fechaBaja.a,cad);
    return !hayError;
}

void generarMensajeError(int i, char * aux){
    switch(i){
        case 0 :
            strcpy(aux,"Error en DNI");
            break;
        case 1 :
            strcpy(aux,"|Error en Fecha de nacimiento");
            break;
        case 2 :
            strcpy(aux,"|Error en Sexo");
            break;
        case 3 :
            strcpy(aux,"|Error en Fecha de Ingreso");
            break;
        case 4 :
            strcpy(aux,"|Error en Carrera");
            break;
        case 5 :
            strcpy(aux,"|Error en Materias Aprobadas");
            break;
        case 6 :
            strcpy(aux,"|Error en Fecha de ultima materia aprobada");
            break;
        case 7 :
            strcpy(aux,"|Error en Estado");
            break;
        case 8 :
            strcpy(aux,"|Error en Fecha de Baja");
            break;
        default:
            strcpy(aux,"|Sin errores");
    }
}
void mostrarArchivoAlumnos(char *path){
    FILE *fp = fopen(path,"rb");
    if(!fp){
        puts("No se pudo abrir el archivo");
        exit(1);
    }
    t_alumno alu;
    fread(&alu,sizeof(t_alumno),1,fp);
    printf("%-10s  %-25s  %-9s  %s \t %-9s  %s  %s  %-9s %10s \t%-9s \n","DNI","Apellido y Nombre","Fe.Nac","Sexo","Fe.Ing","Carrera","Cant.Aprob","Fe.aprob","Estado","Fe.Baja");
    while(!feof(fp)){
        printf("%-10li  %-25s  %02d/%02d/%02d  %c \t %02d/%02d/%02d  %-3s \t %2d \t\t %02d/%02d/%02d \t %c \t\t %02d/%02d/%02d \n",
               alu.dni, alu.AyN, alu.fechaNac.d, alu.fechaNac.m, alu.fechaNac.a, alu.sexo, alu.fechaIng.d,
               alu.fechaIng.m, alu.fechaIng.a, alu.carrera, alu.matAprob, alu.fechaAprobUltima.d,
               alu.fechaAprobUltima.m, alu.fechaAprobUltima.a, alu.estado, alu.fechaBaja.d, alu.fechaBaja.m, alu.fechaBaja.a);
        fread(&alu,sizeof(t_alumno),1,fp);
    }
    fclose(fp);
}

void mostrarArchivoBin(char * path){
    FILE *fp = fopen(path,"rb");
    t_reg_indice aux;
    printf("\nARCHIVO INDICDE ");
    fread(&aux, sizeof(t_reg_indice),1,fp);
    while(!feof(fp)){
      printf("\n DNI : %lu",aux.dni);
      printf("\n Nro REG : %d",aux.nro_reg);
      fread(&aux, sizeof(t_reg_indice),1,fp);
    }
    fclose(fp);
}

void listBregister(char * path){
    FILE * fpAlu;
    t_alumno alu;
    if(!(fpAlu=fopen(path,"rb"))){
        printf("Error al abrir el archivo de alumnos");
        exit(1);
    }
    fread(&alu,sizeof(t_alumno),1,fpAlu);
    printf("********** ALUMNOS DADOS DE BAJA **********");
    printf("\n DNI \t Apellido y nombre \t Sexo \t Fecha de ingreso \t Carrera \t Materias Aprobadas \t Fecha ult. materia aprobada \t Fecha baja");
    while(!feof(fpAlu)){
        if(alu.estado == 'B')
            printf("\n %ld \t %s \t %c \t %d/%d/%d \t %s \t %d \t %d/%d/%d \t %d/%d/%d",
                   alu.dni,alu.AyN,alu.sexo, alu.fechaIng.d,alu.fechaIng.m,alu.fechaIng.a,
                   alu.carrera,alu.matAprob, alu.fechaAprobUltima.d,alu.fechaAprobUltima.m,
                   alu.fechaAprobUltima.a, alu.fechaBaja.d,alu.fechaBaja.m,alu.fechaBaja.a);
        fread(&alu,sizeof(t_alumno),1,fpAlu);
    }
    fclose(fpAlu);
}

void mostrarNoBajas(char * path){
    t_indice indice;
    t_reg_indice tAux;
    ind_crear(&indice);
    ind_cargar(&indice,path);
    printf("********** ALUMNOS NO DADOS DE BAJA **********");
    printf("\n DNI \t Apellido y nombre \t Sexo \t Fecha de ingreso \t Carrera \t Materias Aprobadas \t Fecha ult. materia aprobada \t Fecha baja");
    ind_primero(&indice,&tAux);
    //ind_siguiente(&indice,&tAux);
    while(!ind_fin(&indice)){
        imprimir(&tAux);
        ind_siguiente(&indice,&tAux);
    }
}

void imprimir(t_reg_indice* reg_ind){
    FILE *fp = fopen("AlumnosBin.dat","rb");
    t_alumno alu;
    int n = reg_ind->nro_reg;
    fseek(fp,(n-1)*sizeof(t_alumno),SEEK_SET);
    fread(&alu,sizeof(t_alumno),1,fp);
    if(alu.estado != 'B')
        printf("\n %ld \t %s \t %c \t %d/%d/%d \t %s \t %d \t %d/%d/%d \t %d/%d/%d",
               alu.dni,alu.AyN,alu.sexo, alu.fechaIng.d,alu.fechaIng.m,alu.fechaIng.a,
               alu.carrera,alu.matAprob, alu.fechaAprobUltima.d,alu.fechaAprobUltima.m,
               alu.fechaAprobUltima.a, alu.fechaBaja.d,alu.fechaBaja.m,alu.fechaBaja.a);
}

void indexToMemory(FILE *fidx ,t_indice * indice){
    t_reg_indice regIndice;
    fread(&regIndice,sizeof(t_reg_indice),1,fidx);
    while(!feof(fidx)){
        ind_insertar(indice,&regIndice);
        fread(&regIndice,sizeof(t_reg_indice),1,fidx);
    }
}

void grabarArchivoidx(t_reg_indice *  dato_indice,void *fidx){
        FILE * fpidx = (FILE *)fidx;
        fwrite(dato_indice,sizeof(t_reg_indice),1,fpidx);
}

void mostrarMenu(void){
    printf("\n--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
    printf("-------------||-||-|||-||-|-|--|------------------\n");
    printf("-------------||-||-||--|-||-|--|------------------\n");
    printf("-------------|-|-|-|---|--|-|--|------------------\n");
    printf("-------------|---|-|||-|--|-||||------------------\n");
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
    printf("- Efectuar Mantenimientos/Altas/Bajas: 1\n");
    printf("- Listar los dados de baja: 2\n");
    printf("- Listarlos en orden sin los dados de baja: 3\n\n");
    printf("- Salir: 4\n\n");
}
