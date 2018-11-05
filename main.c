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
    leerArchivo("arbol.txt", 1);
    crearArchivo("recorrido.txt", "PreOrden: ");
    preOrden(raiz, "recorrido.txt");
    escribirArchivo2("recorrido.txt", "\nInOrden: ");
    inOrden(raiz, "recorrido.txt");
    escribirArchivo2("recorrido.txt", "\nPostOrden: ");
    postOrden(raiz, "recorrido.txt");
    leerArchivo("eliminar.txt", 4);
    crearArchivo("recorridoE.txt", "PreOrden: ");
    preOrden(raiz, "recorridoE.txt");
    escribirArchivo2("recorridoE.txt", "\nInOrden: ");
    inOrden(raiz, "recorridoE.txt");
    escribirArchivo2("recorridoE.txt", "\nPostOrden: ");
    postOrden(raiz, "recorridoE.txt");
    crearArchivo("nivelS.txt", "");
    leerArchivo("nivel.txt", 2);
    crearArchivo("pesosS.txt", "");
    leerArchivo("pesos.txt", 3);
    return (EXIT_SUCCESS);
}
