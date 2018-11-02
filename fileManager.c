#include <stdio.h>

void leerArchivo(){
    FILE *file = fopen("arboles.txt", "rt");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    
    int c;
    while((c=fgetc(file)) != EOF){
        putchar(c);
    }
}