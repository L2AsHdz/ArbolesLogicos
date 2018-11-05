#include <stdio.h>
#include <stdlib.h>

struct nodo {
    char info;
    struct nodo *padre;
    struct nodo *izquierda;
    struct nodo *derecha;
};

struct nodo *raiz = NULL;

void insertar(char c){
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info = c;
    nuevo->padre = NULL;
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
            nuevo->padre = anterior;
            anterior->izquierda = nuevo;
        }else {
            nuevo->padre = anterior;
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
            printf("\nEl nivel de %c es %i", reco->info, nivel);
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
    while (actual != NULL) {
        if (c == actual->info) {
            int pesoIzq = recorrerIzquierda(actual->izquierda, 0);
            int pesoDer = recorrerDerecha(actual->derecha, 0);
            printf("\nse encontro el nodo %c", actual->info);
            printf(" %i,%i", pesoIzq, pesoDer);
            escribirArchivoPeso(actual->info,pesoIzq,pesoDer);
            break;
        }else {
            if (c > actual->info) {
                actual = actual->derecha;
            }else {
                actual = actual->izquierda;
            }
        }
    }
}

int recorrerIzquierda(struct nodo *actual, int pesoI){
    if (actual != NULL) {
        pesoI++;
        pesoI = recorrerIzquierda(actual->izquierda, pesoI);
        pesoI = recorrerIzquierda(actual->derecha, pesoI);
    }
    return pesoI;
}

int recorrerDerecha(struct nodo *actual, int pesoD){
    if (actual != NULL) {
        pesoD++;
        pesoD = recorrerDerecha(actual->izquierda, pesoD);
        pesoD = recorrerDerecha(actual->derecha, pesoD);
    }
    return pesoD;
}

int isHoja(struct nodo *actual){
    int boolean = 0;
    if (recorrerIzquierda(actual,0) == 0 && recorrerDerecha(actual,0) == 0) {
        boolean = 1;
    }
    return boolean;
}

int isNodo1Hijo(struct nodo *actual){
    int boolean = 0;
    if (recorrerIzquierda(actual,0) >= 1 && recorrerDerecha(actual,0) == 0) {
        boolean = 1;
    }else if (recorrerIzquierda(actual,0) == 0 && recorrerDerecha(actual,0) >= 1) {
        boolean = 2;
    }
    return boolean;
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

void imprimirPadres(struct nodo *actual){
    if (actual != NULL) {
        if (actual->padre != NULL) {
            printf("\nEl padre de %c es: %c", actual->info, actual->padre->info);
        }
        imprimirPadres(actual->izquierda);
        imprimirPadres(actual->derecha);
    }
}