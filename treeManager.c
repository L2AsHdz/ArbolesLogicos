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
        struct nodo *anterior, *reco;
        anterior = NULL;
        reco = raiz;
        while(reco != NULL){
            anterior = reco;
            if (c < reco->info) {
                reco = reco->izquierda;
            }else {
                reco = reco->derecha;
            }
        }
        
        if (c < anterior->info) {
            anterior->izquierda = nuevo;
        }else {
            anterior->derecha = nuevo;
        }
    }
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

void borrar(struct nodo *reco)
{
    if (reco != NULL)
    {
        borrar(reco->izquierda);
        borrar(reco->derecha);
        free(reco);
    }
}