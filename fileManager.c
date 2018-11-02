#include <stdio.h>
#include "header.h"

void leerArchivo(){
    FILE *file = fopen("arbol.txt", "rt");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    
    char c;
    while((c=fgetc(file)) != EOF){
        insertar(c);
    }
    
    fclose(file);
}

void crearArchivo(){
    FILE *file = fopen("recorrido.txt", "w");
    
    if (file == NULL){
        printf("Error en la creacion del archivo");
        return 1;
    }
    fprintf(file, "PreOrden: ");
    fclose(file);
}

void escribirArchivo(char c){
    FILE *file = fopen("recorrido.txt", "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fputc(c,file);
    fclose(file);
}

void escribirArchivo2(){
    FILE *file = fopen("recorrido.txt", "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fprintf(file, "\nInOrden: ");
    fclose(file);
}

void escribirArchivo3(){
    FILE *file = fopen("recorrido.txt", "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fprintf(file, "\nPostOrden: ");
    fclose(file);
}