/* 
 * File:   main.c
 * Author: Asael
 *
 * Created on 2 de noviembre de 2018, 01:32 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

extern struct nodo *raiz;

int main(int argc, char** argv) {
    leerArchivo();
    crearArchivo();
    preOrden(raiz);
    escribirArchivo2();
    inOrden(raiz);
    escribirArchivo3();
    postOrden(raiz);
    leerArchivoEliminar();
    crearArchivoEliminar();
    preOrdenE(raiz);
    escribirArchivo2E();
    inOrdenE(raiz);
    escribirArchivo3E();
    postOrdenE(raiz);
    crearArchivoNivel();
    leerArchivoNivel();
    crearArchivoPeso();
    leerArchivoPeso();
    imprimirPadres(raiz);
    return (EXIT_SUCCESS);
}
