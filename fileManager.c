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

void leerArchivoNivel(){
    FILE *file = fopen("nivel.txt", "rt");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    
    char c;
    while((c=fgetc(file)) != EOF){
        nivel(c);
    }
    
    fclose(file);
}

void leerArchivoPeso(){
    FILE *file = fopen("pesos.txt", "rt");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    
    char c;
    while((c=fgetc(file)) != EOF){
        encontrarNodo(c);
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

void crearArchivoNivel(){
    FILE *file = fopen("nivelS.txt", "w");
    
    if (file == NULL){
        printf("Error en la creacion del archivo");
        return 1;
    }
    fclose(file);
}

void crearArchivoPeso(){
    FILE *file = fopen("pesosS.txt", "w");
    
    if (file == NULL){
        printf("Error en la creacion del archivo");
        return 1;
    }
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

void escribirArchivoNivel(int in){
    FILE *file = fopen("nivelS.txt", "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fprintf(file, "%i,", in);
    fclose(file);
}

void escribirArchivoPeso0(char c){
    FILE *file = fopen("pesosS.txt", "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fprintf(file, "Para %c: ", c);
    fclose(file);
}

void escribirArchivoPeso(int peso1, int peso2){
    FILE *file = fopen("pesosS.txt", "at");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    fprintf(file, "%i %i \n", peso1, peso2);
    fclose(file);
}