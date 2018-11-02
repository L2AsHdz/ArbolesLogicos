/* 
 * File:   main.c
 * Author: Asael
 *
 * Created on 2 de noviembre de 2018, 01:32 AM
 */

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    FILE *file = fopen("arboles.txt", "rt");
    
    if (file == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }
    
    int c;
    while((c=fgetc(file)) != EOF){
        putchar(c);
    }
    return (EXIT_SUCCESS);
}

