#include <stdio.h>
#include "header.h"

void leerArchivo(char nameFile[], int typeFile){
    FILE *file = fopen(nameFile, "rt");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    
    char c;
    while((c=fgetc(file)) != EOF){
        switch(typeFile){
            case 1:
                insertar(c);
                break;
                
            case 2:
                nivel(c);
                break;
            
            case 3:
                peso(c);
                break;
                
            case 4:
                eliminar(c);
                break;
        }
    }
    
    fclose(file);
}

void crearArchivo(char nameFile[], char initialText[]){
    FILE *file = fopen(nameFile, "w");
    
    if (file == NULL){
        printf("Error en la creacion del archivo");
        return 1;
    }
    fprintf(file, initialText);
    fclose(file);
}

void escribirArchivo(char c, char nameFile[]){
    FILE *file = fopen(nameFile, "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fputc(c,file);
    fclose(file);
}

void escribirArchivo2(char nameFile[], char text[]){
    FILE *file = fopen(nameFile, "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fprintf(file, text);
    fclose(file);
}

void escribirArchivoNivel(int in){
    FILE *file = fopen("nivelS.txt", "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fprintf(file, "%i,", in);
    fclose(file);
}

void escribirArchivoPeso(char c, int peso1, int peso2){
    FILE *file = fopen("pesosS.txt", "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fprintf(file,"Para %c: Izquierdo %i - Derecho %i \n", c, peso1, peso2);
    fclose(file);
}