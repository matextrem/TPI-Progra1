#include "tp_utils.h"
#include "indice.h"
#include <string.h>
#include <unistd.h>
int main() {
    int isMacOSX = isMacOS();
    char path[30], path2[30];
    t_fecha fecha = {2017,21,10}; ///inicializada
    t_alumno alumno;
    t_alumno * alu = &alumno;
    t_indice indice;
    t_fecha fechaProce;
    FILE *fBin,*fidx;
    printf("\nIngrese la fecha de proceso: ");
    scanf("%d/%d/%d", &fechaProce.d, &fechaProce.m, &fechaProce.a);
    crearArchivoAlumnos(isMacOSX,&fechaProce);
    texto_a_binario("alumnos.txt",&fecha,alu,&indice);
    //mostrarArchivoAlumnos("AlumnosBin.dat");
    //mostrarArchivoBin("AlumnosBin.idx");
    ///char path[30], path2[30]; ///No se puede declarar las variables fuera del inicio del bloque. Cuidado con estas cosas, si bien este compilador lo permite, una ansi no, y hay que programar para que funcione en uno ansi.
    printf("\n Ingrese el nombre del archivo con el que va a trabajar : ");
    clean_stdin(isMacOSX);
    gets(path);
    strcpy(path2, path); ///El problema era que desp del segundo strcat, el path les quedaba "AlumnosBin.dat.idx"
    if(!(fBin=fopen(strcat(path,".dat"),"rb+")) || !(fidx=fopen(strcat(path2,".idx"),"rb"))){
        printf("Error al abrir el archivo");
        exit(1);
    }


    //ind_cargar(&indice,path2); ///Esta función recibe el path, no el puntero al archivo, o sea, que lo abre, carga el indice y cierra el archivo.

    int option,nroRegistros;
    mostrarMenu();
    printf("Ingrese su opcion: ");
    scanf("%d", &option);
    while(option != 4){
        if(option == 1) {
            printf("- Altas: 1\n");
            printf("- Bajas: 2\n");
            printf("Ingrese su opción: ");
            scanf("%d", &option);

            if(option == 1) {
                unsigned long dni;
                fclose(fidx);
                fidx = fopen(path2,"wb");
                t_alumno aluN;
                printf("Ingrese la clave DNI: ");
                scanf("%lu", &dni);
                t_reg_indice reg;
                reg.dni = dni;
                if(!ind_buscar(&indice,&reg)){
                    aluN.dni = dni;
                    printf("Ingrese apellido y nombre: ");
                    clean_stdin(isMacOSX);
                    gets(aluN.AyN);
                    normalizarApyN(aluN.AyN);

                    printf("Ingrese la fecha de nacimiento d/m/aaaa: ");
                    scanf("%d/%d/%d",&aluN.fechaNac.d,&aluN.fechaNac.m,&aluN.fechaNac.a);

                    while(!validarFechaNac(&aluN.fechaNac, &fechaProce)) {
                        printf("Error.Ingrese la fecha de nacimiento d/m/aaaa: ");
                        clean_stdin(isMacOSX);
                        scanf("%d/%d/%d", &aluN.fechaNac.d, &aluN.fechaNac.m, &aluN.fechaNac.a);
                    }
                    printf("Ingrese sexo: ");
                    clean_stdin(isMacOSX);
                    scanf("%c",&aluN.sexo);
                    while(!validarSexo(&aluN.sexo)){
                        printf("Error. Ingrese sexo: ");
                        clean_stdin(isMacOSX);
                        scanf("%c",&aluN.sexo);
                    }

                    printf("Ingresar fecha de ingreso d/m/aaaa: ");
                    clean_stdin(isMacOSX);
                    scanf("%d/%d/%d",&aluN.fechaIng.d,&aluN.fechaIng.m,&aluN.fechaIng.a);
                    while(!validarFechaIng(&aluN.fechaIng, &aluN.fechaNac, &fechaProce)) {
                        printf("Error.Ingresar fecha de ingreso d/m/aaaa: ");
                        clean_stdin(isMacOSX);
                        scanf("%d/%d/%d",&aluN.fechaIng.d,&aluN.fechaIng.m,&aluN.fechaIng.a);
                    }

                    printf("Ingresar carrera: ");
                    clean_stdin(isMacOSX);
                    gets(aluN.carrera);
                    while(!validarCarrera(aluN.carrera)) {
                        printf("Error. Ingresar carrera: ");
                        clean_stdin(isMacOSX);
                        scanf("%s", aluN.carrera);
                    }

                    printf("Ingrese la cantidad de materias aprobadas: ");
                    scanf("%d",&aluN.matAprob);
                    while(!validarMateriasAprobadas(&aluN.matAprob)) {
                        printf("Error.Ingrese la cantidad de materias aprobadas: ");
                        scanf("%d",&aluN.matAprob);
                    }

                    printf("Ingresar fecha de aprobacion de ultima materia d/m/aaaa: ");
                    scanf("%d/%d/%d",&aluN.fechaAprobUltima.d,&aluN.fechaAprobUltima.m,&aluN.fechaAprobUltima.a);
                    while(!validarFechaUltimaAprob(&aluN.fechaAprobUltima, &aluN.fechaIng, &fechaProce)) {
                        printf("Error.Ingresar fecha de aprobacion de ultima materia d/m/aaaa: ");
                        scanf("%d/%d/%d",&aluN.fechaAprobUltima.d,&aluN.fechaAprobUltima.m,&aluN.fechaAprobUltima.a);
                    }

                    aluN.estado = 'R';
                    aluN.fechaBaja.d = 31;
                    aluN.fechaBaja.m = 12;
                    aluN.fechaBaja.a = 9999;
                    fseek(fBin,0L,SEEK_END);
                    nroRegistros = ftell(fBin)/sizeof(t_alumno);
                    fwrite(&aluN,sizeof(t_alumno),1,fBin);
                    reg.nro_reg = (unsigned)(nroRegistros+1);
                    ind_insertar(&indice,&reg);
                    recorrer_lista(&indice.lista, fidx, action_write_idx);
                    printf("Alumno ingresado correctamente.");
                    fclose(fBin);
                    fclose(fidx);

                }else printf("El usuario ya se encuentra creado");
            } else if (option == 2) {
                unsigned long dni;
                fBin = fopen(path,"rb+");
                printf("Ingrese la clave DNI: ");
                scanf("%lu", &dni);
                t_alumno aluE;
                t_reg_indice reg;
                reg.dni = dni;
                if(ind_buscar(&indice,&reg)){
                    fseek(fBin, (reg.nro_reg - 1)*sizeof(t_alumno), SEEK_SET);
                    fread(&aluE,sizeof(t_alumno),1,fBin);
                    aluE.estado = 'B';
                    fseek(fBin,-sizeof(t_alumno), SEEK_CUR);
                    fwrite(&aluE,sizeof(t_alumno),1,fBin);
                    ind_eliminar(&indice,&reg);
                    printf("\n Usuario dado de baja correctamente.");
                    fclose(fBin);
                } else printf("El usuario no existe");
            } else {
                printf("La manqueaste, te dije del 1 al 3");
            }

        } else if (option == 2) {
            //Lista los registros dados de baja (ESTADO = B) del archivo AlumnosBin.dat
            listBregister(path);
        } else if (option == 3) {
            fclose(fidx);
            mostrarNoBajas(path2);
        } else if(option == 4) {
            exit(0);
        }else{
            printf("La manqueaste, te dije del 1 al 4");
        }
        getchar();
        getchar();
        mostrarMenu();
        printf("\nIngrese su opcion: ");
        scanf("%d", &option);
    }
    fclose(fidx);
    if(!(fidx=fopen(strcat(path,".idx"),"wb"))){
        printf("Error al abrir el archivo");
        exit(1);
    }
    ind_recorrer(&indice,grabarArchivoidx,fidx);
    fclose(fBin);
    fclose(fidx);
    ind_vaciar(&indice);
    return 0;
}
