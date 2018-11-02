#include <stdio.h>
#include <stdlib.h>

struct nodo {
    char info;
    struct nodo *izquierda;
    struct nodo *derecha;
};

struct nodo *raiz = NULL;

void insertar(char c){
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info = c;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    
    if (raiz == NULL) {
        raiz = nuevo;
    }else {
        struct nodo *anterior, *actual;
        anterior = NULL;
        actual = raiz;
        while(actual != NULL){
            anterior = actual;
            if (c < actual->info) {
                actual = actual->izquierda;
            }else {
                actual = actual->derecha;
            }
        }
        
        if (c < anterior->info) {
            anterior->izquierda = nuevo;
        }else {
            anterior->derecha = nuevo;
        }
    }
}

void nivel(char c){
    struct nodo *reco = raiz;
    int nivel = 1;
    while (reco != NULL){
        if (c == reco->info){
            escribirArchivoNivel(nivel);
            printf("%i",nivel);
            break;
        }else {
            if (c>reco->info){
                nivel++;
                reco = reco->derecha;
            }else {
                nivel++;
                reco = reco->izquierda;
            }
        }
    }
}

void encontrarNodo(char c){
    struct nodo *actual = raiz;
    while (actual != NULL){
        if (c == actual->info){
            recorrerNodo(actual);
            break;
        }else {
            if (c>actual->info){
                actual = actual->derecha;
                recorrerNodo(actual);
            }else {
                actual = actual->izquierda;
                recorrerNodo(actual);
            }
        }
    }
}

void recorrerNodo(struct nodo *actual){
    int pesoIzq = 0;
    int pesoDer = 0;
    struct nodo *temp = actual;
    while (actual != NULL) {
        actual = actual->izquierda;
        if (actual != NULL) pesoIzq++;
    }
    actual = temp;
    while (actual != NULL) {
        actual = actual->derecha;
        if (actual != NULL) pesoDer++;
    }
    escribirArchivoPeso(pesoIzq, pesoDer);
    printf("izq: %i - der: %i",pesoIzq,pesoDer);
}

void preOrden(struct nodo *reco){
    if (reco != NULL) {
        escribirArchivo(reco->info);
        printf("%c", reco->info);
        preOrden(reco->izquierda);
        preOrden(reco->derecha);
    }
}

void inOrden(struct nodo *reco){
    if (reco != NULL) {
        inOrden(reco->izquierda);
        escribirArchivo(reco->info);
        printf("%c", reco->info);
        inOrden(reco->derecha);
    }
}

void postOrden(struct nodo *reco){
    if (reco != NULL) {
        postOrden(reco->izquierda);
        postOrden(reco->derecha);
        escribirArchivo(reco->info);
        printf("%c", reco->info);
    }
}

/*void borrar(struct nodo *reco)
{
    if (reco != NULL)
    {
        borrar(reco->izquierda);
        borrar(reco->derecha);
        free(reco);
    }
}*/